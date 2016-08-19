#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

constexpr unsigned MaxSize = 20000;
unsigned Values[MaxSize];
unsigned long Count[2][MaxSize];
unsigned N = 0;

unsigned maxDepth(unsigned begin, unsigned end, int pivot)
{
    if (begin >= end) return 0;

    unsigned returnValue = 0;

    std::vector<int> splitPoints;
    if (pivot == 0)
    {
        unsigned beginIter = begin;
        Count[0][beginIter] = Values[beginIter];

        do
        {
            if (Count[0][beginIter] == Count[1][beginIter + 1] && Values[beginIter] != 0)
            {
                splitPoints.push_back(beginIter + 1);
            }

            ++beginIter;
            Count[0][beginIter] = Count[0][beginIter - 1] + Values[beginIter];
        }
        while (beginIter < end);
    }
    else
    {
        unsigned endIter = end;
        Count[1][endIter] = Values[endIter];

        do
        {
            if (Count[0][endIter - 1] == Count[1][endIter] && Values[endIter] != 0)
            {
                splitPoints.push_back(endIter);
            }

            --endIter;
            Count[1][endIter] = Count[1][endIter + 1] + Values[endIter];
        }
        while (endIter > begin);
    }

    for (auto splitPoint : splitPoints)
    {
        auto leftDepth = 1 + maxDepth(begin, splitPoint - 1, 1);
        auto rightDepth = 1 + maxDepth(splitPoint, end, 0);
        returnValue = std::max(std::max(returnValue, leftDepth), rightDepth);
    }

    return returnValue;
}

int main()
{
#ifdef FILEINPUT
    freopen("nikitaandthegame.dat","r",stdin);
#endif

    unsigned T = 0;
    std::cin >> T;

    for (int testCase = 0; testCase < T; ++testCase)
    {
        std::cin >> N;

        for (int i = 0; i < N; ++i)
        {
            std::cin >> Values[i];
        }

        Count[0][0] = Values[0];
        for (int i = 1; i < N; ++i)
        {
            Count[0][i] = Count[0][i - 1] + Values[i];
        }
        std::cout << (Count[0][N - 1] == 0 ? N - 1 : maxDepth(0, N - 1, 1)) << std::endl;
    }

    return 0;
}


