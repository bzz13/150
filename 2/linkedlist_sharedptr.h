#pragma once
#include <memory>
#include <ostream>
#include <initializer_list>

using namespace std;

template<typename T>
class linkedlist
{
    template<typename TT> struct node
    {
        node(TT t): data(t) { }
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
        auto tmp = head;
        while(tmp->next)
        {
            tmp = tmp->next;
        }
        tail = tmp;
    }

public:
    linkedlist() { }

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

    linkedlist(initializer_list<T> list): linkedlist()
    {
        for (auto l: list)
        {
            add(l);
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
            auto tmp = head;
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

    void clear()
    {
        head = nullptr;
        tail = nullptr;
    }

    friend ostream& operator<<(ostream& os, const linkedlist<T>& list)
    {
        auto tmp = list.head;
        while(tmp)
        {
            os << tmp->data << " -> ";
            tmp = tmp->next;
        }
        os << "nullptr";
        return os;
    }
};