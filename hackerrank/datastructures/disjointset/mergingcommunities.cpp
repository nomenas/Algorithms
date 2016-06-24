#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory>
#include <cstdio>

std::vector<unsigned> graph;
std::vector<unsigned> sizes;

unsigned root(unsigned index)
{
    while (graph[index] != index)
    {
        index = graph[index];
    }

    return index;
}

int main()
{
#ifdef FILEINPUT
    freopen("mergingcommunities.dat", "r", stdin);
#endif
    std::cin.sync_with_stdio(false);
    std::cout.sync_with_stdio(false);

    unsigned N = 0;
    unsigned Q = 0;
    std::cin >> N >> Q;

    graph.resize(N);
    sizes.resize(N);

    for (int i = 0; i < N; ++i)
    {
        graph[i] = i;
        sizes[i] = 1;
    }

    for (int i = 0; i < Q; ++i)
    {
        std::string cmd;
        std::cin >> cmd;
        if (cmd == "Q")
        {
            unsigned itemID = 0;
            std::cin >> itemID;
            std::cout << sizes[root(itemID)] << std::endl;
        }
        else if (cmd == "M")
        {
            unsigned item1ID = 0;
            unsigned item2ID = 0;
            std::cin >> item1ID >> item2ID;

            unsigned root1ID = root(item1ID);
            unsigned root2ID = root(item2ID);

            if (root1ID != root2ID)
            {
                if (sizes[root1ID] < sizes[root2ID])
                {
                    graph[root1ID] = root2ID;
                    sizes[root2ID] += sizes[root1ID];
                }
                else
                {
                    graph[root2ID] = root1ID;
                    sizes[root1ID] += sizes[root2ID];
                }
            }
        }
    }

    return 0;
}

