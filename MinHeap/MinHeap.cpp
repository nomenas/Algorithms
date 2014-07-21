class MinHeap
{
public:
    MinHeap(int size)
        : m_nSize(size)
    {
        m_values = new int[size];
        m_indexes = new int[size];

        for (int i = 0; i < m_nSize; ++i)
        {
            m_values[i] = std::numeric_limits<int>::max();
            m_indexes[i] = i;
        }

        m_values[0] = 0;
    }

    ~MinHeap()
    {
        delete[] m_values;
        delete[] m_indexes;
    }

    void setValue(int index, int value)
    {
        m_values[index] = value;
        heapify(index);
    }

    void removeMin()
    {
        removeAt(0);
    }

    int value() const
    {
        return m_values[0];
    }

    int index() const
    {
        return m_indexes[0];
    }

private:

    void removeAt(int index)
    {
        m_values[index] = m_values[m_nSize - 1];
        m_indexes[index] = m_indexes[m_nSize - 1];
        --m_nSize;

        heapify(index);
    }

    inline void swap(int first, int second)
    {
        std::swap(m_values[first], m_values[second]);
        std::swap(m_indexes[first], m_indexes[second]);
    }

    inline void heapify(int index)
    {
        int parentIndex = (index - 1) / 2;
        if (m_values[index] < m_values[parentIndex])
        {
            while (m_values[index] < m_values[parentIndex])
            {
                swap(parentIndex, index);
                index = parentIndex;
            }
        }
        else
        {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;

            bool isLeftSmaller = (leftChild < m_nSize && m_values[leftChild] < m_values[index]);
            bool isRightSmaller = (rightChild < m_nSize && m_values[rightChild] < m_values[index]);
            while (isLeftSmaller || isRightSmaller)
            {
                if (isLeftSmaller)
                {
                    swap(leftChild, index);
                    index = leftChild;
                }
                else
                {
                    swap(rightChild, index);
                    index = rightChild;
                }
            }
        }
    }

    int m_nSize;
    int* m_values;
    int* m_indexes;
};
