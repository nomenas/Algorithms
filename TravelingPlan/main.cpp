// http://www.codechef.com/problems/TABUS
// http://www.codechef.com/viewsolution/2300137
// http://www.codechef.com/viewsolution/2072463

// dijakstra + min heap no becouse you may filter optimal pat if at begining there is path with less waiting at begining and not egnouht time to arive at time
//

#include <stdio.h>
#include <vector>
#include <limits>

struct Line
{
    int index;
    int V;
    int S;
    int E;
};

int N = 0;
int T = 0;
int M = 0;
std::vector<std::vector<Line> > stationLines;
static int MaxInt = std::numeric_limits<int>::max();
std::vector<int> cache;

int findPath(int currentStation, int currentTime)
{
    int returnValue = MaxInt;

    if (currentStation == N)
    {
        returnValue = 0;
    }
    else if (stationLines[currentStation].size() == 0)
    {
        returnValue = -1;
    }
    else for (unsigned int i = 0; i < stationLines[currentStation].size(); ++i)
    {
        Line& line = stationLines[currentStation][i];
        if (line.E <= T && line.S >= currentTime)
        {
            int cachedWait = cache[line.index];

            if (cachedWait == -2)
            {
                // do nothing
            }
            else if (cachedWait != -1)
            {
                returnValue = std::min(std::max(cachedWait, line.S - currentTime), returnValue);
            }
            else
            {
                cache[line.index] = -2;
                int maxLineDelay = findPath(line.V, line.E);
                if (maxLineDelay != -1)
                {
                    cache[line.index] = maxLineDelay;
                    returnValue = std::min(std::max(maxLineDelay, line.S - currentTime), returnValue);
                }
            }
        }
    }

    return returnValue;
}

int main()
{
    scanf("%d", &N);
    scanf("%d", &T);
    scanf("%d", &M);   
    stationLines.resize(N + 1);
    cache.resize(M);

    for (int i = 0; i < M; ++i)
    {
        int U = 0;
        scanf("%d", &U);
        stationLines[U].push_back(Line());
        stationLines[U].back().index = i;
        cache[i] = -1;
        scanf("%d", &stationLines[U].back().V);
        scanf("%d", &stationLines[U].back().S);
        scanf("%d", &stationLines[U].back().E);
    }

    int maxWait = findPath(1, 0);
    printf("%d\n", maxWait != MaxInt ? maxWait : -1);

    return 0;
}

int main1()
{
    N = 4;
    T = 12;
    M = 5;
    stationLines.resize(N + 1);
    cache.resize(M);

    int lines[5][4] = {{1, 2, 0, 1}, {2, 1, 2, 3}, {1, 3, 3, 4}, {3, 2, 4, 5}, {2, 4, 7, 8}};
    for (int i = 0; i < M; ++i)
    {
        int U = lines[i][0];
        stationLines[U].push_back(Line());
        stationLines[U].back().index = i;
        cache[i] = -1;
        stationLines[U].back().V = lines[i][1];
        stationLines[U].back().S = lines[i][2];
        stationLines[U].back().E = lines[i][3];
    }

    int maxWait = findPath(1, 0);
    printf("%d\n", maxWait != MaxInt ? maxWait : -1);

    return 0;
}
