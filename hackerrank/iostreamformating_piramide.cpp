#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main3()
{
#ifdef FILEINPUT
    freopen("input.dat","r",stdin);
#endif

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cout << std::setw(n - i) << std::setfill(' ') << "#";
        if (i > 0)
        {
            std::cout << std::setw(i) << std::setfill('#') << "#";
        }

        std::cout << std::endl;
    }
    return 0;
}
