#include <iostream>
#include <algorithm>

int main()
{
#ifdef FILEINPUT
    freopen("repeatedstring.dat","r",stdin);
#endif
    std::string input;
    unsigned long lenght = 0;
    std::cin >> input >> lenght;
    
    const auto aInSequence = std::count_if(input.begin(), input.end(), [](char ch) {return ch == 'a';});
    const auto numberOfRepetitions = lenght / input.length();
    const auto leftCharactersInWord = lenght % input.length();
    const auto aInLeftSequence = std::count_if(input.begin(), input.begin() + leftCharactersInWord, [](char ch) {return ch == 'a';});
    
    std::cout << aInSequence * numberOfRepetitions + aInLeftSequence << std::endl;

    return 0;
}

