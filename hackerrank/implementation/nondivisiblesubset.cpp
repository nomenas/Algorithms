#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
#ifdef FILEINPUT
    freopen("nondivisiblesubset.dat","r",stdin);
#endif

    unsigned n = 0;
    std::cin >> n;
    unsigned k = 0;
    std::cin >> k;

    std::vector<unsigned> remainders;
    remainders.resize(k);
    remainders.assign(k, 0);
    unsigned value = 0;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> value;
        ++remainders[value % k];
    }

    unsigned maxSetCount = 0;
    for (int i = 0; i <= k / 2; ++i)
    {
        if (i == 0 || i == double(k) / 2)
        {
            maxSetCount += remainders[i] ? 1 : 0;
        }
        else if (remainders[i] > remainders[k - i])
        {
            maxSetCount += remainders[i];
        }
        else
        {
            maxSetCount += remainders[k - i];
        }
    }

    std::cout << maxSetCount << std::endl;

    return 0;
}
