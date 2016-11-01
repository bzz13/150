#include <iostream>
#include <ostream>
#include <utility>
#include <stack>
#include <vector>

template<typename T>
class queue_with_two_stack
{
    std::stack<T> in;
    std::stack<T> out;
    enum operation_type { push_operation = 0, pop_operation = 1 } last_operation;

    void relocate(std::stack<T>& from, std::stack<T>& to)
    {
        while(!from.empty())
        {
            to.push(from.top());
            from.pop();
        }
    }

public:
    queue_with_two_stack(): last_operation(operation_type::push_operation) { }

    void push(const T data)
    {
        if (last_operation == operation_type::pop_operation)
        {
            relocate(out, in);
        }
        in.push(data);
        last_operation = operation_type::push_operation;
    }

    void pop()
    {
        if (last_operation == operation_type::push_operation)
        {
            relocate(in, out);
        }
        if (!out.empty())
        {
            out.pop();
            last_operation = operation_type::pop_operation;
        }
        else
        {
            throw "queue is empty";
        }
    }

    T top()
    {
        if (last_operation == operation_type::push_operation)
        {
            relocate(in, out);
        }
        if (!out.empty())
        {
            return out.top();
            last_operation = operation_type::pop_operation;
        }
        else
        {
            throw "queue is empty";
        }
    }

    operator bool()
    {
        return !in.empty() || !out.empty();
    }
};

int main()
{
    queue_with_two_stack<int> q;
    q.push(5);
    q.push(6);
    q.push(1);
    q.push(3);

    while(q)
    {
        std::cout << q.top() <<std::endl;
        q.pop();
    }
    std::cout << std::endl;

    q.push(5);
    q.push(6);
    q.push(1);
    q.push(3);
    q.pop();
    q.push(4);
    while(q)
    {
        std::cout << q.top() <<std::endl;
        q.pop();
    }
    return 0;
}