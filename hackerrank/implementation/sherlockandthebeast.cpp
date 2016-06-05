// https://www.hackerrank.com/challenges/sherlock-and-the-beast

#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
#ifdef FILEINPUT
    freopen("sherlockandthebeast.dat","r",stdin);
#endif
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++)
    {
        int n;
        cin >> n;

        int left = n;
        while (left > 0 && left % 3 != 0)
        {
            left -= 5;
        }

        if (left < 0)
        {
            std::cout << -1 << std::endl;
        }
        else
        {
            int i = 0;
            for (;i < left; ++i)
            {
                std::cout << "5";
            }

            for (; i < n; ++i)
            {
                std::cout << "3";
            }

            std::cout << std::endl;
        }
    }

    return 0;
}
