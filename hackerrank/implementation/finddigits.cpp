#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
#ifdef FILEINPUT
    freopen("finddigits.dat","r",stdin);
#endif
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;

        unsigned counter = 0;
        auto iter = n;

        while (iter)
        {
            if (unsigned digit = iter % 10)
            {
                counter += n % digit ? 0 : 1;
            }
            iter = iter / 10;
        }

        std::cout << counter << std::endl;
    }
    return 0;
}


