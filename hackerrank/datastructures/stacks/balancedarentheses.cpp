#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main()
{
#ifdef FILEINPUT
    freopen("balancedarentheses.dat", "r", stdin);
#endif

    unsigned N = 0;
    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        std::string input;
        std::cin >> input;

        std::stack<char> parentlessChecker;
        static char pushDelimiters[] = {'{', '(', '['};
        static char popDelimiters[]  = {'}', ')', ']'};

        bool isValid = true;
        for (int i = 0; i < input.size() && isValid; ++i)
        {
            char ch = input[i];

            if (std::find(pushDelimiters, std::end(pushDelimiters), ch) != std::end(pushDelimiters))
            {
                parentlessChecker.push(ch);
            }
            else
            {
                auto iter = std::find(popDelimiters, std::end(popDelimiters), ch);

                if (iter != std::end(popDelimiters))
                {
                    if (parentlessChecker.empty())
                    {
                        isValid = false;
                    }
                    else if (parentlessChecker.top() !=
                             pushDelimiters[sizeof(popDelimiters) - (std::end(popDelimiters) - iter)])
                    {
                        isValid = false;
                    }
                    else
                    {
                        parentlessChecker.pop();
                    }
                }
            }
        }

        std::cout << (isValid && parentlessChecker.size() == 0 ? "YES" : "NO") << std::endl;
    }

    return 0;
}


