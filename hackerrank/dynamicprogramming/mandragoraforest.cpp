#include <iostream>
#include <vector>
#include <algorithm>

int main (int argc, char** argv)
{
#ifdef FILEINPUT
    freopen("mandragoraforest.dat","r",stdin);
#endif
    unsigned T = 0;
    std::cin >> T;

    for (int testCase = 0; testCase < T; ++testCase)
    {
        unsigned N = 0;
        std::cin >> N;
        std::vector<unsigned long> H;
        H.resize(N);

        for (int i = 0; i < N; ++i)
        {
            std::cin >> H[i];
        }

        std::sort(H.begin(), H.end());
        for (int i = N - 2; i >= 0; --i)
        {
            H[i] += H[i + 1];
        }

        unsigned long max = H[0];
        for (int i = 1; i < N; ++i)
        {
            max = std::max(max, H[i] * (i + 1));
        }
        std::cout << max << std::endl;
    }
    return 0;
}
