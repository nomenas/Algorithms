#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
#ifdef FILEINPUT
    freopen("cavitymap.dat","r",stdin);
#endif
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int grid_i = 0;grid_i < n;grid_i++){
       cin >> grid[grid_i];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0 ; j < n; ++j)
        {
            bool isCavity = false;
            if (i > 0 && j > 0 && i < n - 1 && j < n - 1)
            {
                isCavity = grid[i - 1][j] < grid[i][j] && grid[i + 1][j] < grid[i][j] &&
                    grid[i][j - 1] < grid[i][j] && grid[i][j + 1] < grid[i][j];
            }

            std::cout << (isCavity ? 'X' : grid[i][j]);
        }
        std::cout << std::endl;
    }

    return 0;
}

