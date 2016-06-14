#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isMatrixPresent(const vector<string>& in, const vector<string>& match, int r, int c)
{
    for (int i = 0; i < match.size(); ++i)
    {
        for (int j = 0; j < match[i].size(); ++j)
        {
            if (in[r + i][c + j] != match[i][j]) return false;
        }
    }

    return true;
}

int main()
{
#ifdef FILEINPUT
    freopen("thegridsearch.dat","r",stdin);
#endif
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int R;
        int C;
        cin >> R >> C;
        vector<string> G(R);
        for(int G_i = 0;G_i < R;G_i++){
           cin >> G[G_i];
        }
        int r;
        int c;
        cin >> r >> c;
        vector<string> P(r);
        for(int P_i = 0;P_i < r;P_i++){
           cin >> P[P_i];
        }

        bool matched = false;
        for (int i = 0; i <= R - r && !matched; ++i)
        {
            for (int j = 0; j <= C - c && !matched; ++j)
            {
                matched = isMatrixPresent(G, P, i, j);
            }
        }

        std::cout << (matched ? "YES" : "NO") << std::endl;
    }
    return 0;
}
