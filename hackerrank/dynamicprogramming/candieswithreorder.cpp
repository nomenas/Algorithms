#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
#ifdef FILEINPUT
    freopen("candies.dat","r",stdin);
#endif

    unsigned N = 0;
    std::cin >> N;
    std::vector<unsigned> ranks;
    ranks.resize(N);
    std::vector<unsigned> ordered;
    ordered.resize(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> ranks[i];
    }

    std::sort(ranks.begin(), ranks.end());
    unsigned current = 0;
    unsigned middle = N / 2;
    for (int i = 0; i < middle && ranks[i] != ranks[N - 1 - i]; ++i)
    {
        ordered[current++] = ranks[i];
        ordered[current++] = ranks[N - 1 - i];
    }

    unsigned previousChildCandies = 1;
    unsigned candiesCount = previousChildCandies;
    for (unsigned i = 1; i < N; ++i)
    {
        previousChildCandies = ordered[i] > ordered[i - 1] ? previousChildCandies + 1 : 1;
        candiesCount += previousChildCandies;
    }

    std::cout << candiesCount << std::endl;

    return 0;
}
