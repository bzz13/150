#include <iostream>
#include <stack>

template<typename T>
void sort_stack(std::stack<T>& oredering)
{
    if (oredering.empty())
    {
        return;
    }
    else
    {
        std::stack<T> additional;
        while(!oredering.empty())
        {
            auto tmp = oredering.top();
            oredering.pop();

            if (oredering.empty())
            {
                additional.push(tmp);
                continue;
            }
            if (tmp < oredering.top())
            {
                additional.push(tmp);
            }
            else
            {
                while(!oredering.empty() && tmp > oredering.top())
                {
                    additional.push(oredering.top());
                    oredering.pop();
                }
                oredering.push(tmp);
                while(!additional.empty())
                {
                    oredering.push(additional.top());
                    additional.pop();
                }
            }
        }
        while(!additional.empty())
        {
            oredering.push(additional.top());
            additional.pop();
        }
    }
}

int main()
{
    std::stack<int> s;
    s.push(5);
    s.push(4);
    s.push(1);
    s.push(3);
    s.push(2);

    sort_stack(s);
    while(!s.empty())
    {
        std::cout<< s.top() << std::endl;
        s.pop();
    }

    return 0;
}