#include <memory>
#include <iostream>
#include <vector>

int main()
{
#ifdef FILEINPUT
    freopen("ArrayManipulation.dat", "r", stdin);
#endif

    auto n = 0;
    auto m = 0;
    std::cin >> n >> m;
    std::vector<long> array(n, 0);
    for(int i = 0; i < m; i++){
        int a = 0;
        int b = 0;
        int k = 0;
        std::cin >> a >> b >> k;
        array[a - 1] += k;
        array[b] -= k;
    }

    long long sum = 0;
    long long max = 0;
    for (auto item : array) {
        sum += item;

        if (sum > max) {
            max = sum;
        }
    }

    std::cout << max << std::endl;

    return 0;
}
