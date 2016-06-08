// https://www.hackerrank.com/challenges/maxsubarray

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
#ifdef FILEINPUT
    freopen("themaximumsubarray.dat","r",stdin);
#endif

    unsigned T = 0;
    std::cin >> T;

    while (T--)
    {
        unsigned N = 0;
        std::vector<long> A;

        std::cin >> N;
        A.resize(N);
        for (int i = 0; i < N; ++i)
        {
            std::cin >> A[i];
        }

        long maxContiguousSum = 0;
        long maxNonContiguousSum = 0;
        long maxElement = std::numeric_limits<long>::min();
        long contiguousSum = 0;

        for (int i = 0; i < N; ++i)
        {
            contiguousSum += A[i];
            maxNonContiguousSum = std::max(maxNonContiguousSum, maxNonContiguousSum + A[i]);

            if (contiguousSum < 0)
            {
                contiguousSum = 0;
            }

            maxContiguousSum = std::max(maxContiguousSum, contiguousSum);
            maxElement = std::max(maxElement, A[i]);
        }

        maxContiguousSum = maxElement < 0 ? maxElement : maxContiguousSum;
        maxNonContiguousSum = maxElement < 0 ? maxElement : maxNonContiguousSum;
        std::cout << maxContiguousSum << " " << maxNonContiguousSum << std::endl;
    }

    return 0;
}
