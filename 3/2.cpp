#include <iostream>
#include <ostream>
#include <utility>
#include <stack>
#include <vector>

template<typename T>
class stack_with_min
{
    std::stack<T> m_values;
    std::stack<T> m_minims;
public:
    void push(const T data)
    {
        m_values.push(data);
        m_minims.push((m_minims.empty() || data < m_minims.top() ? data : m_minims.top()));
    }

    std::pair<T,T> pop()
    {
        if (!m_values.empty())
        {
            auto result = std::make_pair(m_values.top(), m_minims.top());
            m_values.pop();
            m_minims.pop();
            return result;
        }
        throw "stack is empty";
    }

    operator bool(){
        return !m_values.empty();
    }
};


template<typename T>
class stack_with_min2
{
    std::stack<std::pair<T, T>> m_values;
public:
    void push(const T data)
    {
        if (m_values.empty())
        {
            m_values.push(std::make_pair(data, data));
        }
        else
        {
            auto top = m_values.top();
            m_values.push(std::make_pair(data, top.second < data ? top.second : data));
        }

    }

    std::pair<T,T> pop()
    {
        if (!m_values.empty())
        {
            auto result = m_values.top();
            m_values.pop();
            return result;
        }
        throw "stack is empty";
    }

    operator bool(){
        return !m_values.empty();
    }
};

int main()
{
    stack_with_min2<int> s;
    s.push(5);
    s.push(6);
    s.push(1);
    s.push(3);

    while(s)
    {
        auto p = s.pop();
        std::cout << p.first << ": " << p.second <<std::endl;
    }
    return 0;
}