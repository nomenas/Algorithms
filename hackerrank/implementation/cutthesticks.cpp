#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
#ifdef FILEINPUT
    freopen("cutthesticks.dat","r",stdin);
#endif
    int n;
    cin >> n;
    vector<int> arr(n);
    int min = std::numeric_limits<int>::max();
    int count = 0;
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
       min = std::min(min, arr[arr_i]);
       count += (arr[arr_i] > 0);
    }

    while (count > 0)
    {
        std::cout << count << std::endl;
        int newMin = std::numeric_limits<int>::max();
        count = 0;
        for (int i = 0; i < n; ++i)
        {
            arr[i] -= min;

            if ((arr[i] > 0))
            {
                newMin = std::min(newMin, arr[i]);
                ++count;
            }
        }

        min = newMin;
    }
    return 0;
}

