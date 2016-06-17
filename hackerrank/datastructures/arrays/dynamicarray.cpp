#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
#ifdef FILEINPUT
    freopen("dynamicarray.dat", "r", stdin);
#endif

    int lastAns = 0;
    int N = 0;
    int Q = 0;
    cin >> N >> Q;

    std::vector<std::vector<int> > matrix;
    matrix.resize(N);
    for (int i = 0; i < Q; ++i)
    {
        int query = 0;
        int x = 0;
        int y = 0;
        cin >> query >> x >> y;

        const int seqIndex = (x ^ lastAns) % N;
        if (query == 1)
        {
            matrix[seqIndex].push_back(y);
        }
        else if (query == 2)
        {
            lastAns = matrix[seqIndex][y % matrix[seqIndex].size()];
            std::cout << lastAns << std::endl;
        }
    }
    return 0;
}
