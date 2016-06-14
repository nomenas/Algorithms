
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
#ifdef FILEINPUT
    freopen("caesarcipher.dat","r",stdin);
#endif
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;

    for (int i = 0; i < s.length(); ++i)
    {
        unsigned char encryptedChar = s[i] + k;
        if ('a' <= s[i] && 'z' >= s[i])
        {
            while (encryptedChar > 'z')
            {
                encryptedChar = 'a' + (encryptedChar - 'z') - 1;
            }
        }
        else if ('A' <= s[i] && 'Z' >= s[i])
        {
            while (encryptedChar > 'Z')
            {
                encryptedChar = 'A' + (encryptedChar - 'Z') - 1;
            }
        }
        else
        {
            encryptedChar = s[i];
        }

        std::cout << encryptedChar;
    }
    std::cout << std::endl;

    return 0;
}

