#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
#ifdef FILEINPUT
    freopen("utopiantree.dat","r",stdin);
#endif

    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;

        unsigned lenght = 1;
        for (int i = 0; i < n; ++i)
        {
            if (i % 2)
            {
                lenght += 1;
            }
            else
            {
                lenght *= 2;
            }
        }

        std::cout << lenght << std::endl;
    }
    return 0;
}
