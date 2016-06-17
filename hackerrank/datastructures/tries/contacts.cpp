#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <memory>
using namespace std;

class Tree
{
    struct Node
    {
        ~Node()
        {
            for (auto& child : children)
            {
                delete child.second;
            }

            children.clear();
        }

        int count = 0;
        std::unordered_map<char, Node*> children;
    };

public:
    Tree() : m_pRoot(new Node)
    {
        m_path.resize(22);
    }

    ~Tree()
    {
        if (m_pRoot)
        {
            delete m_pRoot;
            m_pRoot = 0;
        }
    }

    void add(const std::string& word)
    {
        int currentIndex = 0;
        m_path[0] = m_pRoot;
        for (; currentIndex < word.size(); ++currentIndex)
        {
            Node* current = m_path[currentIndex];
            auto iter = current->children.find(word[currentIndex]);
            if (iter != current->children.end())
            {
                m_path[currentIndex + 1] = ((*iter).second);
            }
            else
            {
                break;
            }
        }

        for (; currentIndex < word.size(); ++currentIndex)
        {
            m_path[currentIndex + 1] = (*(m_path[currentIndex]->children.emplace(
                std::make_pair(word[currentIndex], new Node)).first)).second;
        }

        while (currentIndex >= 0)
        {
            ++m_path[currentIndex--]->count;
        }
    }

    unsigned count(const std::string& word)
    {
        unsigned currentIndex = 0;
        Node* current = m_pRoot;
        for (; currentIndex < word.size(); ++currentIndex)
        {
            auto iter = current->children.find(word[currentIndex]);
            if (iter != current->children.end())
            {
                current = ((*iter).second);
            }
            else
            {
                break;
            }
        }

        return currentIndex == word.size() ? current->count : 0;
    }

private:

    std::vector<Node*> m_path;
    Node* m_pRoot;
};

int main()
{
#ifdef FILEINPUT
    freopen("contacts.dat","r",stdin);
#endif
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    Tree tree;
    int N = 0;
    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        std::string command;
        std::cin >> command;
        std::string word;
        std::cin >> word;

        if (command == "add")
        {
            tree.add(word);
        }
        else if (command == "find")
        {
            std::cout << tree.count(word) << std::endl;
        }
    }
    return 0;
}



