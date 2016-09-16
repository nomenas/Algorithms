#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <limits>
#include <algorithm>

constexpr unsigned short FishTypeMask[] =
{
    0b0000000000,
    0b0000000001,
    0b0000000010,
    0b0000000100,
    0b0000001000,
    0b0000010000,
    0b0000100000,
    0b0001000000,
    0b0010000000,
    0b0100000000,
    0b1000000000
};

constexpr unsigned short AllFishMask[] =
{
    0b0000000000,
    0b0000000001,
    0b0000000011,
    0b0000000111,
    0b0000001111,
    0b0000011111,
    0b0000111111,
    0b0001111111,
    0b0011111111,
    0b0111111111,
    0b1111111111
};

int main()
{
#ifdef FILEINPUT
    freopen("synchronousshopping.dat", "r", stdin);
#endif

    unsigned N = 0;
    unsigned M = 0;
    unsigned K = 0;
    std::cin >> N >> M >> K;

    std::vector<short> marketStock;
    marketStock.resize(N);

    for (unsigned i = 0; i < N; ++i)
    {
        unsigned numberOfFishTypes = 0;
        std::cin >> numberOfFishTypes;

        short marketDesciptor = 0;
        for (unsigned j = 0; j < numberOfFishTypes; ++j)
        {
            unsigned fishType = 0;
            std::cin >> fishType;
            marketDesciptor |= FishTypeMask[fishType];
        }
        marketStock[i] = marketDesciptor;
    }

    // nodeId<destination, distance>
    std::vector<std::unordered_map<unsigned short, unsigned long>> graph;
    graph.resize(N);
    for (unsigned i = 0; i < M; ++i)
    {
        unsigned short x = 0;
        unsigned short y = 0;
        unsigned short z = 0;

        std::cin >> x >> y >> z;
        graph[x - 1].emplace(y - 1, z);
        graph[y - 1].emplace(x - 1, z);
    }

    // nodeId<collectedFishTypes, pathPassed>
    std::vector<std::unordered_map<unsigned short, unsigned long>> path;
    path.resize(N);
    path[0].emplace(marketStock[0], 0);

    // <node id, collectedFishTypes>
    std::queue<std::pair<unsigned short, unsigned short> > tasks;
    tasks.push(std::make_pair(0, marketStock[0]));

    while (!tasks.empty())
    {
        const auto& task = tasks.front();
        const auto iter = path[task.first].find(task.second);
        const auto destinationUntilHere = iter != path[task.first].end() ? iter->second : 0;

        for (const auto& dest : graph[task.first])
        {
            const auto currentFishState = task.second | marketStock[dest.first];
            const auto destinationToNextShop = destinationUntilHere + dest.second;

            auto iter = path[dest.first].find(currentFishState);
            if (iter == path[dest.first].end())
            {
                path[dest.first].emplace(currentFishState, destinationToNextShop);
                tasks.push(std::make_pair(dest.first, currentFishState));
            }
            else if (iter->second > destinationToNextShop)
            {
                path[dest.first][currentFishState] = destinationToNextShop;
                tasks.push(std::make_pair(dest.first, currentFishState));
            }
        }

        tasks.pop();
    }

    unsigned long minPath = std::numeric_limits<unsigned long>::max();
    for (const auto& smallCat : path[N - 1])
    {
        for (const auto& largeCat : path[N - 1])
        {
            const auto totalCollected = smallCat.first | largeCat.first;
            if (totalCollected == AllFishMask[K])
            {
                const auto passedPath = std::max(smallCat.second, largeCat.second);
                minPath = std::min(minPath, passedPath);
            }
        }
    }

    std::cout << minPath << std::endl;

    return 0;
}
