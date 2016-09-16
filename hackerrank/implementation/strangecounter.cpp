#include <iostream>
#include <vector>
#include <limits>

int main()
{
#ifdef FILEINPUT
    freopen("strangecounter.dat", "r", stdin);
#endif
    unsigned long t = 0;
    std::cin >> t;

    unsigned long periodLenght = 3;
    unsigned long offset = 0;
    while (offset + periodLenght < t)
    {
        offset += periodLenght;
        periodLenght *= 2;
    }

    std::cout << periodLenght - (t - offset - 1) << std::endl;

    return 0;
}
