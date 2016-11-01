#include <iostream>
#include <ostream>
#include <utility>
#include <stack>
#include <vector>

template<typename T>
class stack_with_min: public std::stack<std::pair<T, T>>
{
    typedef std::pair<T, T> p;
    typedef std::stack<p> basestack;
public:
    void push(const T data)
    {
        if (basestack::empty())
        {
            basestack::push(std::make_pair(data, data));
        }
        else
        {
            auto top = basestack::top();
            basestack::push(std::make_pair(data, top.second < data ? top.second : data));
        }
    }

    p top()
    {
        if (!basestack::empty())
        {
            return basestack::top();
        }
        throw "stack is empty";
    }

    void pop()
    {
        if (!basestack::empty())
        {
            basestack::pop();
        }
        else
        {
            throw "stack is empty";
        }
    }

    operator bool()
    {
        return !basestack::empty();
    }
};

int main()
{
    stack_with_min<int> s;
    s.push(5);
    s.push(6);
    s.push(1);
    s.push(3);

    while(s)
    {
        auto p = s.top();
        std::cout << p.first << ": " << p.second <<std::endl;
        s.pop();
    }
    return 0;
}