// https://www.hackerrank.com/challenges/bear-and-workbook

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
#ifdef FILEINPUT
    freopen("lisasworkbook.dat","r",stdin);
#endif

    int n = 0;
    int k = 0;
    std::cin >> n >> k;

    int specialProblemsCount = 0;
    int currentPage = 1;
    for (int chapter = 0; chapter < n; ++chapter)
    {
        int t = 0;
        cin >> t;
        int maxT = t;
        int pageFirstProblemIndex = 1;
        int pageLastProblemIndex = std::min(k, maxT);

        while (t > 0)
        {
            t -= k;

            if (currentPage >= pageFirstProblemIndex && currentPage <= pageLastProblemIndex)
            {
                ++specialProblemsCount;
            }
            ++currentPage;
            pageFirstProblemIndex += k;
            pageLastProblemIndex = std::min(maxT, pageLastProblemIndex + k);
        }
    }

    std::cout << specialProblemsCount << std::endl;

    return 0;
}

