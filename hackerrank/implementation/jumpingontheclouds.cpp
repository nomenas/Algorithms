
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
#ifdef FILEINPUT
    freopen("jumpingontheclouds.dat","r",stdin);
#endif

    int n = 0;
    std::cin >> n;

    std::vector<int> clouds;
    clouds.resize(n);
    std::vector<int> path;
    clouds.resize(n);
    path.assign(n, 0);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> clouds[i];
    }

    path[1] = 1;
    for (int i = 2; i < n; ++i)
    {
        path[i] = path[i - (clouds[i - 2] == 0 ? 2 : 1)] + 1;
    }

    std::cout << path[n - 1] << std::endl;

    return 0;
}
