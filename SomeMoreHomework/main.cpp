#include <stdio.h>
#include <memory>
#include <string.h>

unsigned char Data[100];
unsigned char OnesCount[100];
unsigned int CurrentCountOfOnes = 0;

void calculateNextNumberOnesCount()
{
    unsigned int current = 0;

    while (true)
    {
        if (Data[current] == 255)
        {
            CurrentCountOfOnes -= OnesCount[current];
            Data[current] = 0;
            OnesCount[current] = 0;
            ++current;
        }
        else
        {
            CurrentCountOfOnes -= OnesCount[current];
            int numOfOnes = 0;
            int number = ++Data[current];

            while (number)
            {
                numOfOnes += (number & 1);
                number = number >> 1;
            }

            OnesCount[current] = numOfOnes;
            CurrentCountOfOnes += OnesCount[current];

            break;
        }
    }
}

void resetOnesCounter()
{
    memset(Data, 0, 100);
    memset(OnesCount, 0, 100);
    CurrentCountOfOnes = 0;
}

static unsigned char AllowedSequences[4][8] = {
    {0, 1, 1, 0, 0, 1, 1, 0},
    {0, 1, 1, 0, 1, 0, 0, 1},
    {1, 0, 0, 1, 1, 0, 0, 1},
    {1, 0, 0, 1, 0, 1, 1, 0}
};

static unsigned char NotPossible[3][4] = {{0, 0, 0, 0}, {1, 1, 1, 1}, {0, 1, 0, 1}};

bool isPatternPossible(unsigned int currentPos, int index, unsigned char* input)
{
    bool returnValue = true;

    if (index > 3)
    {
        int relativeIndex = 0;

        switch (currentPos % 4)
        {
        case 0:
            relativeIndex = 5;
            break;
        case 1:
            relativeIndex = 6;
            break;
        case 2:
            relativeIndex = 7;
            break;
        case 3:
            relativeIndex = 0;
            break;
        default:
            break;
        }

        int compareLenght = std::min(index + 1, relativeIndex);
        int compareInputFrom = index - compareLenght + 1;
        int comparePaternFrom = relativeIndex - compareLenght + 1;
        returnValue = memcmp(&input[compareInputFrom], &AllowedSequences[0][comparePaternFrom], compareLenght) == 0 ||
                      memcmp(&input[compareInputFrom], &AllowedSequences[1][comparePaternFrom], compareLenght) == 0 ||
                      memcmp(&input[compareInputFrom], &AllowedSequences[2][comparePaternFrom], compareLenght) == 0 ||
                      memcmp(&input[compareInputFrom], &AllowedSequences[3][comparePaternFrom], compareLenght) == 0;

        if (returnValue && index > 5 && relativeIndex == 0)
        {
            int compareLenght = std::min(index, 8);
            int compareInputFrom = index - compareLenght;
            int comparePaternFrom = 8 - compareLenght;
            returnValue = (memcmp(&input[compareInputFrom],
                &AllowedSequences[input[index] == 1 ? 2 : 0][comparePaternFrom], compareLenght) != 0);
        }
    }
    else if (index > 1 &&
            (memcmp(&input[index - 2], NotPossible[0], 3) == 0 || memcmp(&input[index - 2], NotPossible[1], 3) == 0))
    {
        returnValue = false;
    }
    else if (index == 3)
    {
        returnValue = (memcmp(&input[0], NotPossible[2], 4) != 0);
    }

    return returnValue;
}

int main()
{
#ifdef MY_DATA
    freopen("/Users/nomenas/Projects/Algorithms/SomeMoreHomework/input.dat", "r", stdin);
#endif

    unsigned int numOfTestCases = 0;
    scanf("%d", &numOfTestCases);

    for (unsigned int testCase = 0; testCase < numOfTestCases; ++testCase)
    {
        resetOnesCounter();
        unsigned int p = 0;
        scanf("%d", &p);

        unsigned char input[1000000];
        for (unsigned int i = 0; i < p; ++i)
        {
            scanf("%d", (int*) &input[i]);
        }

        unsigned int currentPos = 0;
        unsigned int currentInputPos = 0;
        unsigned int printedUntil = 0;

        while (printedUntil < p)
        {
            bool getNextNumber = true;
            if (input[currentInputPos] != (CurrentCountOfOnes % 2) || currentInputPos == p)
            {
                if (currentInputPos && currentInputPos > printedUntil)
                {
                    unsigned int printValue = currentPos - currentInputPos;
                    for (unsigned int i = currentInputPos - printedUntil; i > 0; --i)
                    {
                        printf("%u ", printValue);
                    }
                    getNextNumber = false;
                    printedUntil = currentInputPos;
                }

                currentInputPos = 0;
            }
            else
            {
                ++currentInputPos;
            }

            if (currentInputPos > printedUntil && !isPatternPossible(currentPos, currentInputPos, input))
            {
                unsigned int printValue = currentPos - currentInputPos + 1;
                for (unsigned int i = currentInputPos - printedUntil; i > 0; --i)
                {
                    printf("%u ", printValue);
                }
                printedUntil = currentInputPos;

                for (unsigned int i = printedUntil; i < p; ++i)
                {
                    printf("-1 ");
                }
                printedUntil = p;
            }
            else if (getNextNumber)
            {
                calculateNextNumberOnesCount();
                currentPos++;
            }
        }

        printf("\n");
    }

    return 0;
}

