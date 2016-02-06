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
    
    if (start >= end || lenght == 0)
    {
        returnValue = 0;
    }
    else if (cache[start][end] != -1)
    {
        returnValue = cache[start][end];
    }
    else
    {
        int numOfSameValues = 0;
        if (array[start] == array[end])
        {
            numOfSameValues = 2;
            while (start + 1 < end && array[start] == array[start + 1])
            {
                start = start + 1;
                numOfSameValues += 1;
            }
            
            while (start < end - 1 && array[end] == array[end - 1])
            {
                end = end - 1;
                numOfSameValues += 1;
            }
        }
        
        returnValue = maxPalindrome(start + 1, end - 1, array, lenght);
        
        if (array[start] == array[end])
        {
            if (returnValue == 0 && start + 1 != end && numOfSameValues % 2 == 0)
            {
                numOfSameValues += 1;
            }
                
            returnValue += numOfSameValues;
        }
        else
        {
            returnValue = std::max(returnValue, maxPalindrome(start + 1, end, array, lenght));
            returnValue = std::max(returnValue, maxPalindrome(start, end - 1, array, lenght));
            
            if (start == 0 && end == lenght -1 && returnValue == 0)
            {
                returnValue = 1;
            }
        }

        cache[start][end] = returnValue;
    }
    
    return returnValue;
}

int main(int argc, const char * argv[])
{
    {
        memset(cache, -1, sizeof(cache[0][0]) * 100 * 100);
        int array[] = {2, 2, 1, 2, 2};
        int lenght = sizeof(array) / sizeof(int);
        printf("%d\n", 5 == maxPalindrome(0, lenght - 1, array, lenght));
    }
    {
        memset(cache, -1, sizeof(cache[0][0]) * 100 * 100);
        int array[] = {2, 2, 1, 2};
        int lenght = sizeof(array) / sizeof(int);
        printf("%d\n", 3 == maxPalindrome(0, lenght - 1, array, lenght));
    }
    {
        memset(cache, -1, sizeof(cache[0][0]) * 100 * 100);
        int array[] = {2, 2, 2, 2};
        int lenght = sizeof(array) / sizeof(int);
        printf("%d\n", 4 == maxPalindrome(0, lenght - 1, array, lenght));
    }
    {
        memset(cache, -1, sizeof(cache[0][0]) * 100 * 100);
        int array[] = {1, 2, 2, 2};
        int lenght = sizeof(array) / sizeof(int);
        printf("%d\n", 3 == maxPalindrome(0, lenght - 1, array, lenght));
    }
    {
        memset(cache, -1, sizeof(cache[0][0]) * 100 * 100);
        int array[] = {1, 2, 2, 4};
        int lenght = sizeof(array) / sizeof(int);
        printf("%d\n", 2 == maxPalindrome(0, lenght - 1, array, lenght));
    }
    {
        memset(cache, -1, sizeof(cache[0][0]) * 100 * 100);
        int array[] = {1, 2, 4, 1};
        int lenght = sizeof(array) / sizeof(int);
        printf("%d\n", 3 == maxPalindrome(0, lenght - 1, array, lenght));
    }
    {
        memset(cache, -1, sizeof(cache[0][0]) * 100 * 100);
        int array[] = {1, 2, 4, 3};
        int lenght = sizeof(array) / sizeof(int);
        printf("%d\n", 1 == maxPalindrome(0, lenght - 1, array, lenght));
    }
    return 0;
}
