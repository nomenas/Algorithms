#include <iostream>

int main()
{
#ifdef FILEINPUT
    freopen("savetheprisoner.dat","r", stdin);
#endif

    unsigned t = 0;
    std::cin >> t;
    for (unsigned i = 0; i < t; ++i)
    {
        unsigned N = 0;
        unsigned M = 0;
        unsigned S = 0;
        std::cin >> N >> M >> S;

        auto prisionersUntilEnd = N - S + 1;
        if (M > prisionersUntilEnd)
        {
            M -= prisionersUntilEnd;
            auto lastPrisioner = (M % N);
            std::cout << (lastPrisioner ? lastPrisioner : N) << std::endl;
        }
        else
        {
            std::cout << S + M - 1 << std::endl;
        }
    }

    return 0;
}
