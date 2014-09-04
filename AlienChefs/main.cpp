// http://www.codechef.com/problems/DOWNLOAD

#include <stdio.h>
#include <algorithm>
#include <vector>

int N = 0;
std::vector<int> Recipes[2];

bool start_compare(int i, int j) { return (Recipes[0][i] < Recipes[0][j]); }
bool end_compare(int i, int end) { return (Recipes[1][i] < end); }

class RangeTreeNode
{
public:
    RangeTreeNode(int index)
        : m_index(index)
        , m_left(0)
        , m_right(0)
        , m_sortByEnd(1, index)
        , m_maxIndex(index)
    {
    }

    RangeTreeNode(RangeTreeNode* left, RangeTreeNode* right)
        : m_index(left->m_maxIndex)
        , m_left(left)
        , m_right(right)
        , m_maxIndex(right->m_maxIndex)
    {
        m_sortByEnd.resize(left->m_sortByEnd.size() + right->m_sortByEnd.size());

        unsigned int leftIndex = 0;
        unsigned int rightIndex = 0;

        unsigned int index = 0;

        while (leftIndex < left->m_sortByEnd.size() || rightIndex < right->m_sortByEnd.size())
        {
            if ((Recipes[1][left->m_sortByEnd[leftIndex]] < Recipes[1][right->m_sortByEnd[rightIndex]] &&
                 leftIndex < left->m_sortByEnd.size()) || rightIndex >= right->m_sortByEnd.size())
            {
                m_sortByEnd[index++] = left->m_sortByEnd[leftIndex++];
            }
            else
            {
                m_sortByEnd[index++] = right->m_sortByEnd[rightIndex++];
            }
        }
    }

    ~RangeTreeNode()
    {
        if (m_left) delete m_left;
        if (m_right) delete m_right;
    }

    RangeTreeNode* rootNode(int begin, int end) const
    {
        RangeTreeNode* root = const_cast<RangeTreeNode*>(this);

        while (root && !(Recipes[0][root->m_index] >= begin && Recipes[0][root->m_index] <= end))
        {
            root = (begin > Recipes[0][root->m_index]) ? root->m_right : root->m_left;
        }

        return root;
    }

    int m_index;
    RangeTreeNode* m_left;
    RangeTreeNode* m_right;
    std::vector<int> m_sortByEnd;
    int m_maxIndex;
};

RangeTreeNode* RangeTree = 0;

void buildRangeTree()
{
    std::vector<int> start_sort;
    start_sort.resize(N);
    for (int i = 0; i < N; ++i) {start_sort[i] = i;}
    std::sort(start_sort.begin(), start_sort.end(), start_compare);

    RangeTreeNode* nodesInLevel[N];
    nodesInLevel[0] = 0;
    int numOfnodesInLevel = N;
    for (int i = 0; i < numOfnodesInLevel; ++i)
    {
        nodesInLevel[i] = new RangeTreeNode(start_sort[i]);
    }

    while (numOfnodesInLevel > 1)
    {
        for (int i = 0; i < numOfnodesInLevel / 2; ++i)
        {
            nodesInLevel[i] = new RangeTreeNode(nodesInLevel[2 * i], nodesInLevel[2 * i + 1]);
        }

        if (numOfnodesInLevel % 2)
        {
            nodesInLevel[numOfnodesInLevel / 2] = nodesInLevel[numOfnodesInLevel - 1];
            numOfnodesInLevel = numOfnodesInLevel / 2 + 1;
        }
        else
        {
            numOfnodesInLevel /= 2;
        }
    }

    RangeTree = nodesInLevel[0];
}

int countEndLaterThan(RangeTreeNode* node, int end)
{
    int returnValue = 0;

    if (node)
    {
        std::vector<int>::iterator iter = std::lower_bound(node->m_sortByEnd.begin(), node->m_sortByEnd.end(), end, end_compare);
        returnValue = node->m_sortByEnd.end() - iter;
    }

    return returnValue;
}

int execQuery(std::vector<int>& query)
{
    int returnValue = 0;

    if (RangeTree && query.size())
    {
        std::sort(query.begin(), query.end());

        int previousValue = 0;
        for (unsigned int i = 0; i < query.size(); ++i)
        {
            RangeTreeNode* rootNode = RangeTree->rootNode(previousValue, query[i]);

            if (rootNode)
            {
                // process right tree
                RangeTreeNode* node = rootNode->m_right;
                RangeTreeNode* previousNode = 0;
                if (node == 0 && Recipes[0][rootNode->m_index] <= query[i])
                {
                    returnValue += countEndLaterThan(rootNode, query[i]);
                }
                else while (node || previousNode)
                {
                    if (node == 0 && previousNode && Recipes[0][previousNode->m_index] <= query[i])
                    {
                        returnValue += countEndLaterThan(previousNode, query[i]);
                        previousNode = 0;
                    }
                    else if (node == 0)
                    {
                        previousNode = 0;
                    }
                    else
                    {
                        previousNode = node;
                        if (Recipes[0][node->m_index] <= query[i])
                        {
                            returnValue += countEndLaterThan(node->m_left, query[i]);
                            node = node->m_right;
                        }
                        else
                        {
                            node = node->m_left;
                        }
                    }
                }

                // process left tree
                node = rootNode->m_left;
                previousNode = 0;
                while (node || previousNode)
                {
                    if (node == 0 && previousNode && Recipes[0][previousNode->m_index] >= previousValue)
                    {
                        returnValue += countEndLaterThan(previousNode, query[i]);
                        previousNode = 0;
                    }
                    else if (node == 0)
                    {
                        previousNode = 0;
                    }
                    else
                    {
                        previousNode = node;
                        if (Recipes[0][node->m_index] >= previousValue)
                        {
                            returnValue += countEndLaterThan(node->m_right, query[i]);
                            node = node->m_left;
                        }
                        else
                        {
                            node = node->m_right;
                        }
                    }
                }
            }

            previousValue = query[i] + 1;
        }

    }

    return returnValue;
}

int main()
{
#ifdef MY_DATA
    freopen("/Users/nomenas/Projects/Algorithms/AlienChefs/test.dat", "r", stdin);
#endif

    scanf("%d", &N);
    Recipes[0].resize(N);
    Recipes[1].resize(N);
    for (int i = 0; i < N; ++i)
    {
        scanf("%d%d", &Recipes[0][i], &Recipes[1][i]);
    }

    buildRangeTree();

    int Q = 0;
    scanf("%d", &Q);
    for (int i = 0; i < Q; ++i)
    {
        int K = 0;
        scanf("%d", &K);

        std::vector<int> query;
        query.resize(K);
        for (int j = 0; j < K; ++j)
        {
            scanf("%d", &query[j]);
        }

        printf("%d\n", execQuery(query));
    }

    delete RangeTree;

    return 0;
}

