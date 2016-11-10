#include <iostream>
#include <stack>

//a -> b -> c
//c -> b -> a

template<typename T>
class Node
{
public:
    T data;
    Node<T>* next;
};

template<typename T>
Node<T>* reverse(Node<T>* n)
{
    if (!n)
    {
        return n;
    }
    std::stack<Node<T>*> st;
    auto runner = n;
    while(runner)
    {
        st.push(runner);
        runner = runner->next;
    }
    
    n = st.top();
    st.pop();
    
    runner = n;
    while(!st.empty())
    {
        runner->next = st.top();
        runner = runner->next;
        runner->next = nullptr;
        st.pop();
    }
    return n;
    
    /*
    std::stack<T> st;
    auto runner = n;
    while(runner)
    {
        st.push(runner->data);
        runner = runner->next;
    }
    
    runner = n;
    while(!st.empty())
    {
        runner->data = st.top();
        st.pop();
        runner = runner->next;
    }
    */
}

int main()
{
    Node<char>* head = new Node<char>{'a', new Node<char>{ 'b', new Node<char>{'c', nullptr}}};
    
    auto runner = head;
    while(runner)
    {
        std::cout << runner->data << " -> ";
        runner = runner->next;
    }
    std::cout<<std::endl;
    head = reverse(head);
    runner = head;
    while(runner)
    {
        std::cout << runner->data << " -> ";
        runner = runner->next;
    }
    
}