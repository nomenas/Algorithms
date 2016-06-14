#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
#ifdef FILEINPUT
    freopen("sherlockandarray.dat", "r", stdin);
#endif
    unsigned T = 0;
    std::cin >> T;

    for (int testCase = 0; testCase < T; ++testCase)
    {
        unsigned N;
        unsigned long rightSum = 0;
        unsigned long leftSum = 0;
        std::vector<unsigned> A;

        std::cin >> N;
        A.resize(N);
        for (int i = 0; i < N; ++i)
        {
            std::cin >> A[i];
            rightSum += A[i];
        }

        bool found = N == 1;
        for (int i = 0; i < N && !found; ++i)
        {
            if (i > 0)
            {
                leftSum += A[i - 1];
            }
            rightSum -= A[i];
            found = leftSum == rightSum;
        }

        std::cout << (found ? "YES" : "NO") << std::endl;
    }


    return 0;
}
