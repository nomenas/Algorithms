#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
#ifdef FILEINPUT
    freopen("chocolatefeast.dat","r",stdin);
#endif

    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int c;
        int m;
        cin >> n >> c >> m;

        unsigned numOfChocklates = n / c;

        unsigned numOfWrappers = numOfChocklates;
        while (numOfWrappers > 0)
        {
            unsigned numOfNewChocolates = numOfWrappers / m;
            if (numOfNewChocolates > 0)
            {
                numOfWrappers = (numOfWrappers - (numOfNewChocolates * m) + numOfNewChocolates);
                numOfChocklates += numOfNewChocolates;
            }
            else
            {
                break;
            }
        }

        std::cout << numOfChocklates << std::endl;
    }
    return 0;
}


