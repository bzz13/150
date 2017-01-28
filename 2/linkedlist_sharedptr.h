#pragma once
#include <memory>
#include <ostream>

using namespace std;

template<typename T>
class linkedlist
{
    template<typename TT> struct node
    {
        node(TT t): data(t), next(nullptr) { }
        TT data;
        shared_ptr<node<TT>> next;
    };

    shared_ptr<node<T>> head;
    shared_ptr<node<T>> tail;

    void recalc_tail()
    {
        if (!head)
        {
            tail = nullptr;
        }
        shared_ptr<node<T>> tmp = head;
        while(tmp->next)
        {
            tmp = tmp->next;
        }
        tail = tmp;
    }

public:
    void add(const T& t)
    {
        if (tail)
        {
            tail->next = make_shared<node<T>>(t);
            tail = tail->next;
        }
        else
        {
            head = make_shared<node<T>>(t);
            tail = head;
        }
    }

    void remove_first_of(const T& t)
    {
        if(!head)
        {
            return;
        }

        if(head->data == t)
        {
            head = head->next;
        }
        else
        {
            shared_ptr<node<T>> tmp = head;
            while(tmp->next)
            {
                if (tmp->next->data == t)
                {
                    tmp->next = tmp->next->next;
                    break;
                }
                tmp = tmp->next;
            }
        }
        recalc_tail();
    }

    friend ostream& operator<<(ostream& os, const linkedlist<T>& list)
    {
        shared_ptr<node<T>> tmp = list.head;
        while(tmp)
        {
            os << tmp->data << " -> ";
            tmp = tmp->next;
        }
        os << " nullptr";
        return os;
    }
};