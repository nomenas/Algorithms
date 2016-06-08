#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main()
{
#ifdef FILEINPUT
    freopen("sparsearrays.dat", "r", stdin);
#endif

    std::unordered_map<std::string, int> hashMap;

    unsigned N = 0;
    std::cin >> N;
    for (unsigned i = 0; i < N; ++i)
    {
        std::string input;
        std::cin >> input;

        if (hashMap.find(input) != hashMap.end())
        {
            hashMap[input] += 1;
        }
        else
        {
            hashMap[input] = 1;
        }
    }

    unsigned Q = 0;
    std::cin >> Q;
    for (unsigned i = 0; i < Q; ++i)
    {
        std::string input;
        std::cin >> input;

        if (hashMap.find(input) != hashMap.end())
        {
            std::cout << hashMap[input] << std::endl;
        }
        else
        {
            std::cout << "0\n";
        }
    }

    return 0;
}
