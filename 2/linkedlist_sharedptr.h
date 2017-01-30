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
    struct node
    {
        node(T t): data(t) { }
        T data;
        shared_ptr<node> next;
    };

    shared_ptr<node> head;
    shared_ptr<node> tail;

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
            tail->next = make_shared<node>(t);
            tail = tail->next;
        }
        else
        {
            head = make_shared<node>(t);
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

    void remove_node(node n)
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

    class iterator
    {
        typedef size_t difference_type; //almost always ptrdif_t
        typedef T value_type;
        typedef T& reference;
        typedef T* pointer;
        typedef std::forward_iterator_tag iterator_category;

        shared_ptr<linkedlist<T>::node> current;
    public:
        iterator(shared_ptr<linkedlist<T>::node> init): current(init) { }
        iterator& operator++() //prefix increment
        {
            if (current)
            {
                current = current->next;
            }
            return (*this);
        }
        iterator operator++(int) //postfix increment
        {
            auto tmp = current;
            if (current)
            {
                current = current->next;
            }
            return iterator(tmp);
        }
        reference operator*()
        {
            return current->data;
        }
        pointer operator->()
        {
            return &(current->data);
        }
        bool operator==(const iterator& other) const
        {
            if (!current && !other.current)
                return true;
            if (current && other.current)
                return &current == &(other.current);
            return false;
        }
        bool operator!=(const iterator& other) const
        {
            return !(*this == other);
        }
        operator bool() const
        {
            return current != nullptr;
        }
    };

    iterator begin()
    {
        return iterator(head);
    }
    iterator end()
    {
        return iterator(nullptr);
    }

    friend ostream& operator<<(ostream& os, linkedlist<T>& list)
    {
        // auto tmp = list.head;
        // while(tmp)
        // {
        //     os << tmp->data << " -> ";
        //     tmp = tmp->next;
        // }
        // os << "nullptr";

        // for (auto tmp = list.begin(); tmp != list.end(); ++tmp)
        // {
        //     os << *tmp << " -> ";
        // }
        // os << "nullptr";

        for(auto t: list)
        {
            os << t << " -> ";
        }
        os << "nullptr";

        return os;
    }

};