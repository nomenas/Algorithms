#include <iostream>

int main()
{
#ifdef FILEINPUT
    freopen("biggerisgreater.dat","r",stdin);
#endif

    unsigned t = 0;
    std::cin >> t;
    for (unsigned i = 0; i < t; ++i)
    {
        std::string input;
        std::cin >>input;

        if (std::next_permutation(input.begin(), input.end()))
        {
            std::cout << input << std::endl;
        }
        else
        {
            std::cout << "no answer" << std::endl;
        }
    }

    return 0;
}
