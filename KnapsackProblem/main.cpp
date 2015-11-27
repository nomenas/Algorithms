// http://www.cs.cmu.edu/~avrim/451f09/lectures/lect1001.pdf
#include <stdio.h>
#include <limits>
#include <algorithm>
#include <vector>
#include <map>

constexpr int values[] = {7, 9, 5, 12, 14, 6, 12};
constexpr int times[] =  {3, 4, 2,  6,  7, 3,  5};
constexpr int size = sizeof(times) / sizeof(int);

int normalCounter = 0;

int maximumValue(int item, int avalibleTime, int path[])
{
    normalCounter++;

    int returnValue = 0;

    if (item >= 0)
    {
        if (times[item] <= avalibleTime)
        {
            int path1[] = {0, 0, 0, 0, 0, 0, 0};
            int maxValueWithoutThisItem = maximumValue(item - 1, avalibleTime, path1);
            int path2[] = {0, 0, 0, 0, 0, 0, 0};
            int maxValueWithThisItem = maximumValue(item - 1, avalibleTime - times[item], path2) + values[item];

            if (maxValueWithoutThisItem > maxValueWithThisItem)
            {
                std::copy(path1, path1 + size, path);
                returnValue = maxValueWithoutThisItem;
            }
            else
            {
                std::copy(path2, path2 + size, path);
                path[item] = 1;
                returnValue = maxValueWithThisItem;
            }
        }
        else
        {
            returnValue = maximumValue(item - 1, avalibleTime, path);
        }
    }

    return returnValue;
}

int dpCounter = 0;
int cache[size][20];

int maximumValueDP(int item, int avalibleTime)
{
    dpCounter++;

    int returnValue = 0;

    if (item >= 0)
    {
        if (cache[item][avalibleTime] != -1)
        {
            returnValue = cache[item][avalibleTime];
        }
        else
        {
            if (times[item] <= avalibleTime)
            {
                returnValue = std::max(maximumValueDP(item - 1, avalibleTime),
                    maximumValueDP(item - 1, avalibleTime - times[item]) + values[item]);
            }
            else
            {
                returnValue = maximumValueDP(item - 1, avalibleTime);
            }

            cache[item][avalibleTime] = returnValue;
        }
    }

    return returnValue;
}

int main(int, char**)
{
    int path[] = {0, 0, 0, 0, 0, 0, 0};
    clock_t begin = clock();
    int resut1 = maximumValue(size - 1, 14, path);
    clock_t end = clock();
    printf("normal recursion %d for %d iterations %ld time\n", resut1, normalCounter, end - begin);

    for (int i = 0; i < size; ++i)
    {
        printf("%d ", path[i]);
    }
    printf("\n");


    std::fill(cache[0], cache[0] + size * 20, -1);
    clock_t begin1 = clock();
    int result2 = maximumValueDP(size - 1, 14);
    clock_t end1 = clock();
    printf("dp %d for %d iterations %ld time\n", result2, dpCounter, end1 - begin1);
    printf("iteration optimization %2f time optimization %2f\n", 1 - double(dpCounter) / normalCounter, 1 - double(end1 - begin1) / (end - begin));

    return 0;
}

