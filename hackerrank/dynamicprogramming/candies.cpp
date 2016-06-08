#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned N = 0;
std::vector<unsigned> ranks;
std::vector<int> candies;

struct Comparator
{
    bool operator()(unsigned a1, unsigned a2) const
    {
        return ranks[a1] > ranks[a2];
    }
};

int candiesCount(unsigned current, int next)
{
    int returnValue = 1;

    if (next >= 0 && next < N && candies[next] != -1)
    {
        if (ranks[current] > ranks[next])
        {
            returnValue = candies[next] + 1;
        }
    }

    return returnValue;
}

int main()
{
#ifdef FILEINPUT
    freopen("candies.dat","r",stdin);
#endif

    std::cin >> N;
    ranks.resize(N);
    std::vector<unsigned> minHeap;
    for (int i = 0; i < N; ++i)
    {
        minHeap.push_back(i);
        std::cin >> ranks[i];
    }

    Comparator comparator;
    std::make_heap(minHeap.begin(), minHeap.end(), comparator);
    candies.assign(N, -1);
    unsigned long count = 0;
    while (!minHeap.empty())
    {
        unsigned current = minHeap.front();
        candies[current] = std::max(
            candiesCount(current, current - 1),
            candiesCount(current, current + 1));
        count += candies[current];
        std::pop_heap(minHeap.begin(), minHeap.end(), comparator);
        minHeap.pop_back();
    }

    std::cout << count << std::endl;

    return 0;
}
