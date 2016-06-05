// https://www.hackerrank.com/challenges/bfsshortreach

#include <vector>
#include <list>
#include <iostream>

class Comparator
{
public:
    Comparator(const std::vector<int>& weights)
        : m_weights(weights)
    {
    }

    bool operator()(size_t index1, size_t index2) const
    {
        return m_weights[index1] < m_weights[index2];
    }
private:
    const std::vector<int>& m_weights;
};

template <class T, class Comparator = std::greater<int> >
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


using Graph = std::vector<std::list<unsigned> >;
using Weights = std::vector<int>;

void calculateWeight(int S, const Graph& graph, Weights& weight)
{
    Comparator comparator(weight);
    Heap<unsigned, Comparator> visitedNodes(comparator);
    visitedNodes.push(S);

    while (!visitedNodes.empty())
    {
        auto current = visitedNodes.pop();

        for (int next : graph[current])
        {
            int nextItemWeight = weight[current] + 6;

            if (nextItemWeight < weight[next] || weight[next] == -1)
            {
                weight[next] = nextItemWeight;
                visitedNodes.push(next);
            }
        }
    }
}

int main()
{
#ifdef FILEINPUT
    freopen("shortestreach.dat","r",stdin);
#endif
    unsigned int T = 0;
    std::cin >> T;

    while (T--)
    {
        unsigned int N = 0;
        unsigned int M = 0;
        unsigned int S = 0;
        std::cin >> N >> M;
        Graph graph;
        std::vector<int> weight;
        weight.assign(N, -1);
        graph.resize(N);

        for (unsigned int i = 0; i < M; ++i)
        {
            unsigned int x = 0;
            unsigned int y = 0;
            std::cin >> x >> y;

            graph[x - 1].push_back(y - 1);
            graph[y - 1].push_back(x - 1);
        }
        std::cin >> S;
        weight[S - 1] = 0;
        calculateWeight(S - 1, graph, weight);

        for (unsigned int i = 0; i < N; ++i)
        {
            if (i == S - 1) continue;

            std::cout << weight[i];
            if (i != N - 1)
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
