#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
#ifdef FILEINPUT
    freopen("componentsinagraph.dat", "r", stdin);
#endif

    unsigned N = 0;
    std::cin >> N;

    unsigned disjointSet[N * 2];
    unsigned disjointSetNodeCount[N * 2];
    for (unsigned i = 0; i < 2 * N; ++i)
    {
        disjointSet[i] = i;
        disjointSetNodeCount[i] = 1;
    }

    auto disjointSetRoot = [&disjointSet](unsigned index) -> std::pair<unsigned, unsigned>
    {
        std::pair<unsigned, unsigned> returnValue = std::make_pair(0, 0);

        while (index != disjointSet[index])
        {
            index = disjointSet[index];
            ++returnValue.second;
        }

        returnValue.first = index;
        return returnValue;
    };

    for (int i = 0; i < N; ++i)
    {
        unsigned g = 0;
        unsigned b = 0;
        std::cin >> g >> b;

        auto gRoot = disjointSetRoot(g - 1);
        auto bRoot = disjointSetRoot(b - 1);

        if (gRoot.first != bRoot.first)
        {
            if (gRoot.second < bRoot.second)
            {
                disjointSet[gRoot.first] = bRoot.first;
                disjointSetNodeCount[bRoot.first] += disjointSetNodeCount[gRoot.first];
            }
            else
            {
                disjointSet[bRoot.first] = gRoot.first;
                disjointSetNodeCount[gRoot.first] += disjointSetNodeCount[bRoot.first];
            }
        }
    }

    unsigned minGraph = std::numeric_limits<unsigned>::max();
    unsigned maxGraph = 0;

    for (int i = 0; i < N; ++i)
    {
        if (i == disjointSet[i] && disjointSetNodeCount[i] > 1)
        {
            minGraph = std::min(minGraph, disjointSetNodeCount[i]);
            maxGraph = std::max(maxGraph, disjointSetNodeCount[i]);
        }
    }

    std::cout << minGraph << " " << maxGraph << std::endl;

    return 0;
}
