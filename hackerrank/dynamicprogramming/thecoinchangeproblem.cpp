// http://algorithms.tutorialhorizon.com/dynamic-programming-coin-change-problem/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//unsigned N = 0;
//unsigned M = 0;
//unsigned coins[50];
//long cache[50][251];

//unsigned possibleOptions(int coinIndex, long amounth)
//{
//    if (coinIndex == -1 || amounth < 0)
//    {
//        return 0;
//    }
//    else if (amounth == 0)
//    {
//        return 1;
//    }
//    else if (cache[coinIndex][amounth] != -1)
//    {
//        return cache[coinIndex][amounth];
//    }
//    else
//    {
//        cache[coinIndex][amounth] =
//            possibleOptions(coinIndex, amounth - coins[coinIndex]) +
//            possibleOptions(coinIndex - 1, amounth);
//    }

//    return cache[coinIndex][amounth];
//}

int main()
{
#ifdef FILEINPUT
    freopen("thecoinchangeproblem.dat","r",stdin);
#endif

    unsigned N = 0;
    unsigned M = 0;
    std::cin >> N >> M;
    unsigned coins[M];

    for (int i = 0; i < M; ++i)
    {
        std::cin >> coins[i];
    }

    std::sort(coins, coins + M, std::less<unsigned>());

    unsigned matrix[M + 1][N + 1];
    for (unsigned i = 0; i <= M; ++i)
    {
        for (unsigned j = 0; j <= N; ++j)
        {
            if (j == 0)
            {
                matrix[i][j] = 1;
            }
            else if (i == 0)
            {
                matrix[i][j] = 0;
            }
            // if left amount of money is bigger that current coin value
            else if (coins[i - 1] <= j)
            {
                // possible optins for returning cache is number of options with smaller coin
                // + number of optins with same coin but with ammount reduced for that coin
                matrix[i][j] = matrix[i - 1][j] + matrix[i][j - coins[i - 1]];
            }
            // otherwise get value from smaller coin
            else
            {
                matrix[i][j] = matrix[i - 1][j];
            }
        }
    }

    std::cout << matrix[M][N] << std::endl;

    return 0;
}
