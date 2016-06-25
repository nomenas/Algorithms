#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

unsigned N = 0;
std::vector<int> tree;

struct Node
{
    int data = 0;
    Node* left = nullptr;
    Node* right = nullptr;
};

void printInOrder(Node* node)
{
    if (node)
    {
        if (node->left)
        {
            printInOrder(node->left);
        }

        std::cout << node->data << " ";

        if (node->right)
        {
            printInOrder(node->right);
        }
    }
}

void print(Node* node)
{
    printInOrder(node);
    std::cout << std::endl;
}

int main()
{
#ifdef FILEINPUT
    freopen("swapnodes.dat","r",stdin);
#endif

    std::cin >> N;

    std::vector<Node*> nodes;
    nodes.push_back(new Node);
    nodes[0]->data = 1;

    for (int i = 0; i < N; ++i)
    {
        int leftData = 0;
        int rightData = 0;
        std::cin >> leftData >> rightData;

        auto addNode = [&nodes](Node*& node, int data)
        {
            node = new Node;
            node->data = data;
            nodes.push_back(node);
        };

        if (leftData != -1)
        {
            addNode(nodes[i]->left, leftData);
        }

        if (rightData != -1)
        {
            addNode(nodes[i]->right, rightData);
        }
    }

    unsigned T = 0;
    std::cin >> T;

    for (int i = 0; i < T; ++i)
    {
        unsigned K = 0;
        std::cin >> K;

        std::queue<std::pair<Node*, unsigned> > queue;
        queue.push(std::make_pair(nodes[0], 1));

        while (!queue.empty())
        {
            auto item = queue.front();
            if (item.second % K == 0)
            {
                std::swap(item.first->left, item.first->right);
            }

            if (item.first->left)
            {
                queue.push(std::make_pair(item.first->left, item.second + 1));
            }
            if (item.first->right)
            {
                queue.push(std::make_pair(item.first->right, item.second + 1));
            }

            queue.pop();
        }

        print(nodes[0]);
    }

    return 0;
}


