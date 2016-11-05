#include <vector>
#include <initializer_list>
#include <functional>
#include <iostream>

template<typename T>
class heap
{
    std::vector<T> m_data;
    std::function<bool(T,T)> m_cmp;

    void swap(const int i, const int j)
    {
        if (i != j)
        {
            auto tmp = m_data[i];
            m_data[i] = m_data[j];
            m_data[j] = tmp;
        }
    }

    void shiftDown(const int i)
    {
        int max_index = m_data.size();
        if (i < max_index)
        {
            int left_child_index = i*2 + 1;
            int right_child_index = i*2 + 2;

            int swap_index = i;
            if (left_child_index < max_index && 
                m_cmp(m_data[left_child_index], m_data[i]))
            {
                swap_index = left_child_index;
            }
            if (right_child_index < max_index &&
                m_cmp(m_data[right_child_index], m_data[swap_index]))
            {
                swap_index = right_child_index;
            }
            if(swap_index != i)
            {
                swap(i, swap_index);
                shiftDown(swap_index);
            }
        }
    }

    void shiftUp(const int i)
    {
        if (i == 0)
        {
            return;
        }
        int parent_index = (i-1) / 2;
        if (m_cmp(m_data[i], m_data[parent_index]))
        {
            swap(i, parent_index);
            shiftUp(parent_index);
        }
    }

    void make_heap()
    {
        for (int i = (m_data.size() - 1) / 2; i >= 0; --i)
        {
            shiftDown(i);
        }
    }

public:
    heap(std::vector<T> data, std::function<bool(T,T)> cmp = std::greater<T>()): m_data(data), m_cmp(cmp)
    {
        make_heap();
    }

    heap(std::initializer_list<T> data, std::function<bool(T,T)> cmp = std::greater<T>()): m_data(data), m_cmp(cmp)
    {
        make_heap();
    }

    void insert(T t)
    {
        m_data.push_back(t);
        shiftUp(m_data.size() - 1);
    }

    std::vector<T> sort()
    {
        std::vector<T> result;
        while(m_data.size() > 0)
        {
            result.push_back(m_data.front());
            swap(0, m_data.size() - 1);
            m_data.pop_back();
            shiftDown(0);
        }
        return result;
    }
};

int main()
{
    heap<int> h({3, 4, 6, 2, 5, 8, 9, 0, 1, 7, 4}, std::less<int>());
    auto sorted = h.sort();
    for(auto s: sorted)
    {
        std::cout << s << " ";
    }
}