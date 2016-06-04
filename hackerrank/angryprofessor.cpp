// https://www.hackerrank.com/challenges/angry-professor

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int angryprofessor()
{
    int t;
    cin >> t;


    for(int a0 = 0; a0 < t; a0++)
    {
        int n;
        int k;
        cin >> n >> k;

        int arrivedOnTimeCount = 0;
        for(int a_i = 0;a_i < n;a_i++)
        {
            int value = 0;
            cin >> value;
            arrivedOnTimeCount += (value <= 0 ? 1 : 0);
        }

        std::cout << ((k <= arrivedOnTimeCount) ? "NO" : "YES") << std::endl;
    }
    return 0;
}
