#include <cmath>
#include <iostream>

int main()
{
#ifdef FILEINPUT
    freopen("sherlockandsquares.dat","r",stdin);
#endif
    unsigned T = 0;
    std::cin >> T;

    for (int i = 0; i < T; ++i)
    {
        unsigned A = 0;
        unsigned B = 0;
        std::cin >> A >> B;

        unsigned lowerBound = ceil(sqrt(A));
        unsigned current = lowerBound;
        while (current * current <= B) ++current;

        std::cout << current - lowerBound << std::endl;
    }
}
