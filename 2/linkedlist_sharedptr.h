#pragma once
#include <memory>
#include <ostream>
#include <initializer_list>
#include <unordered_set>
#include <stdexcept>
#include <stack>

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

    void remove_duplicates_values()
    {
        if (!head)
        {
            return;
        }

        unordered_set<T> vals { head->data };
        auto prev = head;
        auto curr = head->next;
        while(curr)
        {
            if (vals.find(curr->data) == vals.end())
            {
                vals.insert(curr->data);
                prev = curr;
            }
            else
            {
                prev->next = curr->next;
            }
            curr = curr->next;
        }
        recalc_tail();
    }

    void remove_duplicates_values2()
    {
        if (!head)
        {
            return;
        }

        auto tmp = head;
        while(tmp)
        {
            auto curr = tmp;
            auto next = curr->next;
            while(next)
            {
                if (next->data == tmp->data)
                {
                    curr->next = next->next;
                }
                else
                {
                    curr = curr->next;
                }
                next = next->next;
            }
            tmp = tmp->next;
        }
        recalc_tail();
    }

    T find_k_from_end(int k) const
    {
        if (k < 0)
        {
            throw invalid_argument("k must be positive");
        }
        auto fast = head;
        while(fast && k >= 0)
        {
            fast = fast->next;
            k--;
        }
        if (!fast && k > 0)
        {
            throw out_of_range("k is too big");
        }
        auto curr = head;
        while(fast)
        {
            curr = curr->next;
            fast = fast->next;
        }
        return curr->data;
    }

    void remove_node(node<T> n)
    {
        if (!n->next)
        {
            throw invalid_argument("cant remove tail node directly");
        }
        else
        {
            n->data = n->next->data;
            n->next = n->next->next;
        }
    }

    bool is_polindrom()
    {
        if(!head)
        {
            return true;
        }
        auto tmp = head;
        int length = 0;
        while(tmp)
        {
            length++;
            tmp = tmp->next;
        }

        stack<T> st;
        tmp = head;
        for(auto i = 0; i < length/2; i++)
        {
            st.push(tmp->data);
            tmp = tmp->next;
        }
        if (length % 2)
        {
            tmp = tmp->next;
        }
        while(tmp)
        {
            if (tmp->data != st.top())
            {
                return false;
            }
            st.pop();
            tmp = tmp->next;
        }
        return true;
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