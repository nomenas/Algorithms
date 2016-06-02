#include <iomanip>
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
#ifdef FILEINPUT
    freopen("input.dat","r",stdin);
#endif

    string time;
    cin >> time;

    if (time.length() == 10)
    {
        const bool isPM = strcmp(&time[8], "PM") == 0;
        time[2] = '\0';
        time[5] = '\0';
        time[8] = '\0';
        auto hour = atoi(&time[0]);
        auto min = atoi(&time[3]);
        auto sec = atoi(&time[6]);

        if (isPM)
        {
            if (hour < 12)
            {
                hour += 12;
            }
        }
        else if (hour == 12)
        {
            hour = 0;
        }

        std::cout << std::setw(2) << std::setfill('0') << hour << ":"
                  << std::setw(2) << std::setfill('0') << min << ":"
                  << std::setw(2) << std::setfill('0') << sec << std::endl;
    }

    return 0;
}
