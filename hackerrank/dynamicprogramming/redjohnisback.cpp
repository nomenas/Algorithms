#include <iostream>

int main()
{
#ifdef FILEINPUT
    freopen("redjohnisback.dat","r",stdin);
#endif

    unsigned T = 0;
    std::cin >> T;

    constexpr static unsigned MaxN = 40;
    constexpr static unsigned MaxK = MaxN / 4;
    unsigned long C[MaxN + 1][MaxK + 1] = {0};

    // calculate combination matrix
    for (int n = 1; n <= MaxN; ++n)
    {
        for (int k = 0; k <= n && k <= MaxK; ++k)
        {
            if (n == 1 || k == 0 || k == MaxK || k == n)
            {
                C[n][k] = 1;
            }
            else if (n - k > 1)
            {
                C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
            }
            else
            {
                C[n][k] = n;
            }
        }
    }

    constexpr static unsigned MaxC = 217300;
    static bool PrimeMarker[MaxC];
    std::fill_n(PrimeMarker, MaxC, true);
    PrimeMarker[0] = PrimeMarker[1] = false;
    unsigned pivot = 2;
    while (pivot < MaxC)
    {
        unsigned iter = pivot + pivot;
        while (iter < MaxC)
        {
            PrimeMarker[iter] = false;
            iter += pivot;
        }

        // find next pivot
        do
        {
            ++pivot;
        }
        while (pivot < MaxC && !PrimeMarker[pivot]);
    }

    static unsigned PrimeCounter[MaxC];
    std::fill_n(PrimeCounter, MaxC, 0);
    for (unsigned i = 1; i < MaxC; ++i)
    {
        PrimeCounter[i] = PrimeMarker[i] ? (PrimeCounter[i - 1] + 1) : PrimeCounter[i - 1];
    }

    while(T--)
    {
        unsigned N = 0;
        std::cin >> N;

        const int maxK = N / 4;
        unsigned long totalCombinations = 0;
        for (int k = 0; k <= maxK; ++k)
        {
            totalCombinations += C[k + (N - k * 4)][k];
        }

        std::cout << PrimeCounter[totalCombinations] << std::endl;
    }

    return 0;
}
