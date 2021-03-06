// https://www.hackerrank.com/challenges/plus-minus

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main()
{
#ifdef FILEINPUT
    freopen("printingfloat.dat","r",stdin);
#endif

    int n;
    cin >> n;
    float negativeCount = 0;
    float zeroCount = 0;
    float positiveCount = 0;
    for(int arr_i = 0;arr_i < n;arr_i++)
    {
        int value = 0;
        cin >> value;

        if (value < 0)
        {
            ++negativeCount;
        }
        else if (value == 0)
        {
            ++zeroCount;
        }
        else
        {
            ++positiveCount;
        }
    }

    std::cout << std::fixed << positiveCount / n << std::endl;
    std::cout << std::fixed << negativeCount / n << std::endl;
    std::cout << std::fixed << zeroCount / n << std::endl;
    return 0;
}
