#ifndef UTILS_H
#define UTILS_H

void fillCombinationsMatrix(unsigned long** matrix, int N, int K)
{
    for (int n = 1; n <= N; ++n)
    {
        for (int k = 0; k <= n && k <= K; ++k)
        {
            if (n == 1 || k == 0 || k == K || k == n)
            {
                matrix[n][k] = 1;
            }
            else if (n - k > 1)
            {
                matrix[n][k] = matrix[n - 1][k - 1] + matrix[n - 1][k];
            }
            else
            {
                matrix[n][k] = n;
            }
        }
    }
}

void fillPrimeMarkerArray(bool* array, size_t N)
{
    std::fill_n(array, N, true);
    array[0] = array[1] = false;
    unsigned pivot = 2;
    while (pivot < N)
    {
        unsigned iter = pivot + pivot;
        while (iter < N)
        {
            array[iter] = false;
            iter += pivot;
        }

        // find next pivot
        do
        {
            ++pivot;
        }
        while (pivot < N && !array[pivot]);
    }
}

void fillComulativePrimeCounter(unsigned* array, bool* markers, size_t N)
{
    std::fill_n(array, N, 0);
    for (unsigned i = 1; i < N; ++i)
    {
        array[i] = markers[i] ? (array[i - 1] + 1) : array[i - 1];
    }
}

#endif // UTILS_H
