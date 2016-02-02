//
//  main.cpp
//  MaxPalindrome
//
//  Created by Naum Puroski on 2/3/16.
//  Copyright © 2016 purocomputers. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

int cache[100][100] = {-1};
int maxPalindrome(int start, int end, int* array, int lenght)
{
    int returnValue = 0;
    
    if (start > end || lenght == 0)
    {
        returnValue = 0;
    }
    else if (start == end)
    {
        returnValue = 1;
    }
    else if (cache[start][end] != -1)
    {
        returnValue = cache[start][end];
    }
    else
    {
        returnValue = maxPalindrome(start + 1, end - 1, array, lenght);
        returnValue = std::max(returnValue, maxPalindrome(start + 1, end, array, lenght));
        returnValue = std::max(returnValue, maxPalindrome(start, end - 1, array, lenght));
        returnValue += array[start] == array[end] ? 2 : 0;

        cache[start][end] = returnValue;
    }
    
    return returnValue;
}

int main(int argc, const char * argv[])
{
    memset(cache, -1, sizeof(cache[0][0]) * 100 * 100);
    int array[] = {1, 2, 4, 3};

    int lenght = sizeof(array) / sizeof(int);
    printf("%d\n", maxPalindrome(0, lenght - 1, array, lenght));
    return 0;
}
