#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include "../utils/xlong.h"

int main()
{
#ifdef FILEINPUT
    freopen("fibonaccimodified.dat","r",stdin);
#endif

    unsigned int A = 0;
    unsigned int B = 0;
    unsigned int N = 0;
    std::cin >> A >> B >> N;

    XLong n2{A};
    XLong n1{B};
    XLong result{0ULL};

    for (int i = 0; i < N - 2; ++i)
    {
        result = n1 * n1 + n2;
        n2 = n1;
        n1 = result;
    }

    result.print();
    std::cout << std::endl;

    return 0;
}


