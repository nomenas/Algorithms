#include <stdio.h>
#include <vector>
#include <tuple>
#include <limits>

int cellValue(char maze[101][101], int x, int y)
{
    char cell = maze[x][y];

    if (cell >= '0' && cell <= '9')
    {
        return cell - '0';
    }

    return 0;
}

int main(int, char **)
{
#ifdef FILE_INPUT
    freopen("/Users/nomenas/Projects/Algorithms/MazeOfDigits/testdata.txt", "r", stdin);
#endif

    int numOfTestCases = 0;
    scanf("%d", &numOfTestCases);

    while (numOfTestCases--)
    {
        int M, N;
        scanf("%d %d", &M, &N);

        char maze[101][101];
        int startRow, startColumn;
        for (int i = 0; i < M + 1; ++i)
        {
            for (int j = 0; j < N + 1; ++j)
            {
                scanf("%c", &maze[i][j]);

                switch (maze[i][j])
                {
                case 10: --j;
                    break;
                case '*':
                    startRow = i;
                    startColumn = j;
                    break;
                }
            }
        }
        int requiredSum = 0;
        scanf("%d", &requiredSum);

        std::vector<std::tuple<int, int, int> > paths;
        int count = 0;
        bool pathFound = false;
        paths.push_back(std::make_tuple(startRow, startColumn, 0));
        int shortestPath[101][101] = {{std::numeric_limits<int>::max()}};
        int maxCount = std::numeric_limits<int>::max();

        while (!pathFound && paths.size())
        {
            ++count;
            std::vector<std::tuple<int, int, int> > newPaths;

            if (count == maxCount)
            {
                // max count reached
            }
            else for (auto item : paths)
            {
                int x = std::get<0>(item);
                int y = std::get<1>(item);
                int sum = std::get<2>(item);
                shortestPath[x][y] = std::min(shortestPath[x][y], count);

                if (sum == requiredSum)
                {
                    pathFound = true;
                    break;
                }
                else if (sum > requiredSum || maze[x][y] == '#')
                {
                    continue;
                }

                int avaliblePaths = 0;
                if (y > 0 && maze[x][y - 1] != '#')
                {
                    newPaths.push_back(std::make_tuple(x, y - 1, sum + cellValue(maze, x, y - 1)));
                    ++avaliblePaths;
                }
                if (y < N && maze[x][y + 1] != '#')
                {
                    newPaths.push_back(std::make_tuple(x, y + 1, sum + cellValue(maze, x, y + 1)));
                    ++avaliblePaths;
                }
                if (x > 0 && maze[x - 1][y] != '#')
                {
                    newPaths.push_back(std::make_tuple(x - 1, y, sum + cellValue(maze, x - 1, y)));
                    ++avaliblePaths;
                }
                if (x < M && maze[x + 1][y] != '#')
                {
                    newPaths.push_back(std::make_tuple(x + 1, y, sum + cellValue(maze, x + 1, y)));
                    ++avaliblePaths;
                }

                const int currentCellValue = cellValue(maze, x, y);
                if (avaliblePaths == 1 && currentCellValue == 0)
                {
                    maze[x][y] = '#';
                }
                else if (avaliblePaths == 0 && currentCellValue != 0 && requiredSum % currentCellValue == 0)
                {
                    maxCount = shortestPath[x][y] + requiredSum / currentCellValue;
                }
            }

            paths = std::move(newPaths);
        }

        printf("%d\n", pathFound ? count - 1 : (maxCount != std::numeric_limits<int>::max() ? maxCount : -1));
    }

    return 0;
}
