// http://acm.timus.ru/problem.aspx?space=1&num=1005
#include <stdio.h>
#include <algorithm>

int cache[20] = {-1};
int stoneWeight[20]= {5, 8, 13, 27, 14};
int numberOfStones = 5;

int normalCounter = 0;
int dynamicCounter = 0;

int minDistance(int item, int weight1, int weight2)
{
    ++normalCounter;

    if (item > 0)
    {
        int distanceWithoutThisItem = minDistance(item - 1, weight1, weight2);

        weight1 -= stoneWeight[item];
        weight2 += stoneWeight[item];

        int distanceWithThisItem = minDistance(item - 1, weight1, weight2);

        return std::min(distanceWithoutThisItem, distanceWithThisItem);
    }

    return abs(weight1 - weight2);
}

int minDistanceDynamic(int item, int weight1, int weight2)
{
    ++dynamicCounter;

    int returnValue = abs(weight1 - weight2);

    if (item > 0)
    {
        int distanceWithoutThisItem = cache[item - 1] != -1 && cache[item - 1] < returnValue ?
                    cache[item - 1] : minDistanceDynamic(item - 1, weight1, weight2);

        weight1 -= stoneWeight[item];
        weight2 += stoneWeight[item];

        int newDistance = abs(weight1 - weight2);
        int distanceWithThisItem = cache[item - 1] != -1 && cache[item - 1] < newDistance ?
                    cache[item - 1] : minDistanceDynamic(item - 1, weight1, weight2);

        returnValue = std::min(distanceWithoutThisItem, distanceWithThisItem);
    }

    cache[item] = std::min(cache[item], returnValue);
    return returnValue;
}
int main(int, char**)
{
    int weight1 = 0;
    for (int i = 0; i < numberOfStones; ++i)
    {
        weight1 += stoneWeight[i];
    }

    std::fill(cache, cache + 20, 1000000);
    printf("%d calculated for %d iterations\n", minDistance(4, weight1, 0), normalCounter);
    printf("%d calculated for %d iterations\n", minDistanceDynamic(4, weight1, 0), dynamicCounter);

    return 0;
}

