
#include <iostream>
#include <algorithm>
#include <vector>
#include "../../utils/heap.h"

int main()
{
    std::vector<int> v { 3, 1, 4, 1, 5, 9 };

    std::greater<int> comparator;
    std::make_heap(v.begin(), v.end(), comparator);

    std::cout << "v: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';

    v.push_back(6);

    std::cout << "before push_heap: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';

    std::push_heap(v.begin(), v.end(), comparator);

    std::cout << "after push_heap: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';

    std::cout << "v[3] = 10\n";
    v[3] = 10;
    heapify(3, v, comparator);
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';

    while (!v.empty())
    {
        std::cout << v.front() << " ";
        std::pop_heap(v.begin(), v.end(), comparator);
        v.pop_back();
    }
    std::cout << std::endl;
}
