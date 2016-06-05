// https://www.hackerrank.com/challenges/tutorial-intro

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
#ifdef FILEINPUT
    freopen("binarysearch.dat","r",stdin);
#endif

    int V = 0;
    int n = 0;
    cin >> V >> n;

    std::vector<int> ar;
    ar.resize(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> ar[i];
    }

    int begin = 0;
    int end = n - 1;
    int middle = (begin + end) / 2;

    while (end != begin && ar[middle] != V)
    {
        if (ar[middle] > V)
        {
            end = middle - 1;
        }
        else
        {
            begin = middle + 1;
        }

        middle = (begin + end) / 2;
    }

    std::cout << (ar[middle] == V ? middle : -1) << std::endl;

    return 0;
}
