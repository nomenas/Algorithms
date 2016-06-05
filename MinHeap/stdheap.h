#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <algorithm>

template <class T, class Comp>
class Heap
{
public:
    void push(T val)
    {
        m_heap.push_back(val);
        std::push_heap(m_heap.begin(), m_heap.end(), comparator);
    }

    T pop()
    {
        T val = m_heap.front();

        //This operation will move the smallest element to the end of the vector
        std::pop_heap(m_heap.begin(), m_heap.end(), comparator);

        //Remove the last element from vector, which is the smallest element
        m_heap.pop_back();

        return val;
    }

    bool empty() const
    {
        return m_heap.empty();
    }

private:
    std::vector<T> m_heap;
    Comp comparator;
};

#endif //HEAP_H
