#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <algorithm>
#include <functional>

template <class T, class Comparator = std::greater<T> >
class Heap
{
public:
    Heap() : m_comparator(Comparator()) {}
    Heap(Comparator comp) : m_comparator(comp) {}

    void push(T value)
    {
        m_heap.push_back(value);
        heapify(m_heap.size() - 1);
    }

    T pop()
    {
        std::swap(m_heap.front(), m_heap.back());
        T returnValue = m_heap.back();
        m_heap.pop_back();
        heapify(0);

        return returnValue;
    }

    bool empty() const
    {
        return m_heap.empty();
    }

    void heapify(size_t index)
    {
        size_t parentIndex = parent(index);
        bool wasHeapifiedUp = isHeapifyUpNeeded(index, parentIndex);
        while (isHeapifyUpNeeded(index, parentIndex))
        {
            std::swap(m_heap[index], m_heap[parentIndex]);
            index = parentIndex;
            parentIndex = parent(index);
        }

        if (!wasHeapifiedUp)
        {
            while (left(index) < m_heap.size())
            {
                size_t child1 = left(index);
                size_t child2 = child1 + 1;

                size_t largerChild = child1;
                if (child2 < m_heap.size() && m_comparator(m_heap[child2], m_heap[child1]))
                {
                    largerChild = child2;
                }

                if (m_comparator(m_heap[largerChild], m_heap[index]))
                {
                    std::swap(m_heap[index], m_heap[largerChild]);
                    index = largerChild;
                }
                else
                {
                    index = m_heap.size();
                }
            }
        }
    }

private:
    inline bool isHeapifyUpNeeded(size_t index, size_t parentIndex) const
    {
        return index != parentIndex && m_comparator(m_heap[index], m_heap[parentIndex]);
    }

    inline size_t parent(size_t index) const
    {
        return index ? ((index - 1) / 2) : 0;
    }

    inline size_t left(size_t index) const
    {
        return 2 * index + 1;
    }

    inline size_t right(size_t index) const
    {
        return 2 * index + 2;
    }

    std::vector<T> m_heap;
    Comparator m_comparator;
};

template <class T>
using MinHeap = Heap<T, std::less<T> >;
template <class T>
using MaxHeap = Heap<T, std::greater<T> >;

template <class T, class Comparator>
void heapify(size_t index, std::vector<T>& heap, const Comparator& comparator)
{
    size_t parentIndex = index ? ((index - 1) / 2) : 0;
    bool wasHeapifiedUp = index != parentIndex && comparator(heap[parentIndex], heap[index]);
    while (index != parentIndex && comparator(heap[parentIndex], heap[index]))
    {
        std::swap(heap[index], heap[parentIndex]);
        index = parentIndex;
        parentIndex = index ? ((index - 1) / 2) : 0;
    }

    if (!wasHeapifiedUp)
    {
        while (2 * index + 1 < heap.size())
        {
            size_t left = 2 * index + 1;
            size_t right = left + 1;

            size_t largerChild = left;
            if (right < heap.size() && comparator(heap[left], heap[right]))
            {
                largerChild = right;
            }

            if (comparator(heap[index], heap[largerChild]))
            {
                std::swap(heap[index], heap[largerChild]);
                index = largerChild;
            }
            else
            {
                index = heap.size();
            }
        }
    }
}


#endif //HEAP_H
