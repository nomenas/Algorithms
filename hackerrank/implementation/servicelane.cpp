#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
#ifdef FILEINPUT
    freopen("servicelane.dat","r",stdin);
#endif

    int n;
    int t;
    cin >> n >> t;
    vector<unsigned> width(n);
    for(int width_i = 0;width_i < n;width_i++){
       cin >> width[width_i];
    }
    for(int a0 = 0; a0 < t; a0++){
        int i;
        int j;
        cin >> i >> j;

        unsigned minVehicle = std::numeric_limits<unsigned>::max();
        while (i <= j)
        {
            minVehicle = std::min(minVehicle, width[i++]);
        }

        std::cout << minVehicle << std::endl;
    }
    return 0;
}
