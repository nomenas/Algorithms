// input from https://www.hackerrank.com/challenges/bfsshortreach

#include <vector>
#include <list>
#include <iostream>
#include "heap.h"

using Graph = std::vector<std::list<unsigned> >;
using Weights = std::vector<int>;

void calculateWeight(int S, const Graph& graph, Weights& weight)
{
    Heap<unsigned> visitedNodes([&weight](unsigned index1, unsigned index2)
    {
         return weight[index1] < weight[index2];
    });
    visitedNodes.push(S);

    while (!visitedNodes.empty())
    {
        auto current = visitedNodes.pop();

        for (int next : graph[current])
        {
            int nextItemWeight = std::max(0, weight[next]) + 6;

            if (nextItemWeight < weight[next] || weight[next] == -1)
            {
                weight[next] = nextItemWeight;
                visitedNodes.push(next);
            }
        }
    }
}

int dijkstra()
{
    unsigned int T = 0;
    std::cin >> T;

    while (T--)
    {
        unsigned int N = 0;
        unsigned int M = 0;
        unsigned int S = 0;
        std::cin >> N >> M;
        Graph graph;
        std::vector<int> weight;
        weight.assign(N, -1);
        graph.resize(N);

        for (unsigned int i = 0; i < M; ++i)
        {
            unsigned int x = 0;
            unsigned int y = 0;
            std::cin >> x >> y;

            graph[x].push_back(y);
        }
        std::cin >> S;

        calculateWeight(S, graph, weight);

        for (unsigned int i = 0; i < N; ++i)
        {
            std::cout << weight[i];
            if (i != N - 1)
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
