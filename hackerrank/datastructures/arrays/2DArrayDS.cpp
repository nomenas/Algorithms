#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){

#ifdef FILEINPUT
    freopen("2DArrayDS.dat", "r", stdin);
#endif

    vector< vector<int> > arr(6,vector<int>(6));
    for(int arr_i = 0;arr_i < 6;arr_i++){
       for(int arr_j = 0;arr_j < 6;arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }

    auto maxSum = std::numeric_limits<int>::min();
    for (int i = 1; i < 5; ++i)
    {
        for (int j = 1; j < 5; ++j)
        {
            maxSum = std::max(maxSum,
                    arr[i - 1][j - 1] + arr[i - 1][j] + arr[i - 1][j + 1] +
                    arr[i][j] +
                    arr[i + 1][j - 1] + arr[i + 1][j] + arr[i + 1][j + 1]);
        }
    }

    std::cout << maxSum << std::endl;

    return 0;
}


