// http://www.codechef.com/problems/TABUS
// http://www.codechef.com/viewsolution/2300137
// http://www.codechef.com/viewsolution/2072463

// dijakstra + min heap no becouse you may filter optimal pat if at begining there is path with less waiting at begining and not egnouht time to arive at time
//

#include <stdio.h>
#include <vector>
#include <limits>
#include <stack>

struct Line
{
    int index;
    int V;
    int S;
    int E;
};

struct StackItem
{
    StackItem(int lStation, Line* lLine, StackItem* lParent, int lDelay)
        : station(lStation)
        , delay(lDelay)
        , line(lLine)
        , parent(lParent)
    {

    }

    inline int arrivalTime() const
    {
        return line ? line->E : 0;
    }

    inline int originArrivalTime() const
    {
        return parent && parent->line ? parent->line->E : 0;
    }

    int station;
    int delay;
    Line* line;
    StackItem* parent;
};

int N = 0;
int T = 0;
int M = 0;
std::vector<std::vector<Line> > stationLines;
static int MaxInt = std::numeric_limits<int>::max();
std::vector<int> cache;

static const int NotProcessed = MaxInt;
static const int ProcessingInProgress = -2;
static const int NoPath = -1;

int findMinWaitingTime()
{
    int returnValue = -1;

    std::stack<StackItem> stack;
    stack.push(StackItem(1, 0, 0, NotProcessed));

    while (!stack.empty())
    {
        StackItem& currentItem = stack.top();

        if (currentItem.delay != NotProcessed)
        {
            if (currentItem.line)
            {
                cache[currentItem.line->index] = currentItem.delay;

                if (currentItem.delay != NoPath)
                {
                    currentItem.parent->delay = std::min(
                            std::max(currentItem.delay, currentItem.line->S - currentItem.originArrivalTime()),
                            currentItem.parent->delay);
                }
            }
            else
            {
                returnValue = currentItem.delay;
            }

            stack.pop();
        }
        else if (currentItem.station == N)
        {
            currentItem.delay = 0;
        }
        else
        {
            for (size_t i = 0; i < stationLines[currentItem.station].size() && currentItem.delay != 0; ++i)
            {
                Line& line = stationLines[currentItem.station][i];

                if (currentItem.line && currentItem.delay < line.S - currentItem.line->E)
                {
                    // do nothing. found path has smaller delay then first step
                }
                else if (line.E > T)
                {
                    // do nothing. you will late if you get this bus
                }
                else if (cache[line.index] == NotProcessed)
                {
                    cache[line.index] = ProcessingInProgress;
                    stack.push(StackItem(line.V, &line, &currentItem, NotProcessed));
                }
                else if (cache[line.index] != ProcessingInProgress)
                {
                    currentItem.delay = std::min(std::max(cache[line.index], line.S - currentItem.arrivalTime()), currentItem.delay);
                }
            }

            if (&currentItem == &stack.top() && currentItem.delay == NotProcessed)
            {
                currentItem.delay = NoPath;
            }
        }
    }

    return returnValue;
}

int main1()
{
    scanf("%d%d%d", &N, &T, &M);
    stationLines.resize(N + 1);
    cache.resize(M);

    for (int i = 0; i < M; ++i)
    {
        int U = 0;
        scanf("%d", &U);
        stationLines[U].push_back(Line());
        stationLines[U].back().index = i;
        cache[i] = NotProcessed;
        scanf("%d%d%d", &stationLines[U].back().V, &stationLines[U].back().S, &stationLines[U].back().E);
    }

    return 0;
}

int cycle()
{
    N = 4;
    T = 12;
    M = 4;

    stationLines.resize(N + 1);
    cache.resize(M);

    int lines[5][4] = {{1, 2, 0, 1}, {2, 3, 1, 2}, {3, 1, 2, 3}, {2, 4, 2, 4}, {1, 4, 3, 7}};
    for (int  i = 0; i < M; ++i)
    {
        int U = lines[i][0];
        stationLines[U].push_back(Line());
        stationLines[U].back().index = i;
        cache[i] = NotProcessed;
        stationLines[U].back().V = lines[i][1];
        stationLines[U].back().S = lines[i][2];
        stationLines[U].back().E = lines[i][3];
    }

    printf("%d 1\n", findMinWaitingTime());

    return 0;
}


int afterCycleBetterPath()
{
    N = 4;
    T = 12;
    M = 5;

    stationLines.resize(N + 1);
    cache.resize(M);

    int lines[5][4] = {{1, 2, 0, 1}, {2, 3, 1, 2}, {3, 1, 2, 3}, {2, 4, 2, 4}, {1, 4, 3, 7}};
    for (int  i = 0; i < M; ++i)
    {
        int U = lines[i][0];
        stationLines[U].push_back(Line());
        stationLines[U].back().index = i;
        cache[i] = NotProcessed;
        stationLines[U].back().V = lines[i][1];
        stationLines[U].back().S = lines[i][2];
        stationLines[U].back().E = lines[i][3];
    }

    printf("%d 0\n", findMinWaitingTime());

    return 0;
}

int noLines()
{
    N = 2;
    T = 12;
    M = 0;

    stationLines.resize(N + 1);
    cache.resize(M);

    int lines[5][4] = {{1, 2, 0, 1}, {2, 3, 1, 2}, {3, 1, 2, 3}, {2, 4, 2, 4}, {1, 4, 3, 7}};
    for (int  i = 0; i < M; ++i)
    {
        int U = lines[i][0];
        stationLines[U].push_back(Line());
        stationLines[U].back().index = i;
        cache[i] = NotProcessed;
        stationLines[U].back().V = lines[i][1];
        stationLines[U].back().S = lines[i][2];
        stationLines[U].back().E = lines[i][3];
    }

    printf("%d -1\n", findMinWaitingTime());

    return 0;
}

void nominal1()
{
    N = 5;
    T = 7;
    M = 5;

    stationLines.resize(N + 1);
    cache.resize(M);

    int lines[5][4] = {{1, 2, 1, 2}, {1, 5, 3, 4}, {2, 4, 4, 5}, {2, 5, 5, 6}, {4, 5, 6, 7}};
    for (int  i = 0; i < M; ++i)
    {
        int U = lines[i][0];
        stationLines[U].push_back(Line());
        stationLines[U].back().index = i;
        cache[i] = NotProcessed;
        stationLines[U].back().V = lines[i][1];
        stationLines[U].back().S = lines[i][2];
        stationLines[U].back().E = lines[i][3];
    }

    printf("%d 2\n", findMinWaitingTime());
}

void nominal2()
{
    N = 5;
    T = 6;
    M = 5;

    stationLines.resize(N + 1);
    cache.resize(M);

    int lines[5][4] = {{1, 2, 1, 2}, {1, 5, 3, 4}, {2, 4, 4, 5}, {2, 5, 5, 6}, {4, 5, 6, 7}};
    for (int  i = 0; i < M; ++i)
    {
        int U = lines[i][0];
        stationLines[U].push_back(Line());
        stationLines[U].back().index = i;
        cache[i] = NotProcessed;
        stationLines[U].back().V = lines[i][1];
        stationLines[U].back().S = lines[i][2];
        stationLines[U].back().E = lines[i][3];
    }

    printf("%d 3\n", findMinWaitingTime());
}

void nominal3()
{
    N = 5;
    T = 5;
    M = 5;

    stationLines.resize(N + 1);
    cache.resize(M);

    int lines[5][4] = {{1, 2, 1, 2}, {1, 5, 3, 4}, {2, 4, 4, 5}, {2, 5, 5, 6}, {4, 5, 6, 7}};
    for (int  i = 0; i < M; ++i)
    {
        int U = lines[i][0];
        stationLines[U].push_back(Line());
        stationLines[U].back().index = i;
        cache[i] = NotProcessed;
        stationLines[U].back().V = lines[i][1];
        stationLines[U].back().S = lines[i][2];
        stationLines[U].back().E = lines[i][3];
    }

    printf("%d 3\n", findMinWaitingTime());
}

void nominal4()
{
    N = 5;
    T = 4;
    M = 5;

    stationLines.resize(N + 1);
    cache.resize(M);

    int lines[5][4] = {{1, 2, 1, 2}, {1, 5, 4, 5}, {2, 4, 4, 5}, {2, 5, 5, 6}, {4, 5, 6, 7}};
    for (int  i = 0; i < M; ++i)
    {
        int U = lines[i][0];
        stationLines[U].push_back(Line());
        stationLines[U].back().index = i;
        cache[i] = NotProcessed;
        stationLines[U].back().V = lines[i][1];
        stationLines[U].back().S = lines[i][2];
        stationLines[U].back().E = lines[i][3];
    }

    printf("%d -1\n", findMinWaitingTime());
}
int main()
{
//    nominal1();
//    nominal2();
    nominal3();
//    nominal4();
//    noLines();
//    cycle();
//    afterCycleBetterPath();
}
