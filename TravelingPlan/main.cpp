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

static const int NotProcessed = -1;
static const int ProcessingInProgress = -2;
static const int NoPath = - 3;

int findMinWaitingPath(int currentStation, int currentTime)
{
    int returnValue = MaxInt;

    if (currentStation == N)
    {
        returnValue = 0;
    }
    else if (stationLines[currentStation].size() == 0)
    {
        returnValue = NoPath;
    }
    else for (unsigned int i = 0; i < stationLines[currentStation].size() && returnValue != 0; ++i)
    {
        Line& line = stationLines[currentStation][i];
        int lineWaitTime = line.S - currentTime;
        int cachedWaitTime = cache[line.index];

        if (cachedWaitTime >= NotProcessed && line.E <= T && line.S >= currentTime && returnValue > lineWaitTime)
        {
            if (cachedWaitTime != NotProcessed)
            {
                returnValue = std::min(std::max(cachedWaitTime, lineWaitTime), returnValue);
            }
            else
            {
                cache[line.index] = ProcessingInProgress;
                cache[line.index] = findMinWaitingPath(line.V, line.E);
                if (cache[line.index] != NoPath)
                {
                    returnValue = std::min(std::max(cache[line.index], lineWaitTime), returnValue);
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
        cache[i] = NotProcessed;
        scanf("%d", &stationLines[U].back().V);
        scanf("%d", &stationLines[U].back().S);
        scanf("%d", &stationLines[U].back().E);
    }

    int maxWait = findMinWaitingPath(1, 0);
    printf("%d\n", maxWait != MaxInt ? maxWait : -1);

    return 0;
}
