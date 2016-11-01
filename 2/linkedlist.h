#pragma once

#include <memory>
#include <iostream>
#include <ostream>
#include <unordered_set>


template<typename T>
class linkedlist
{
    template<typename TN>
    struct node
    {
        TN    m_data;
        node* m_next;
    };

    node<T>* m_head;

    node<T>* remove(node<T>* current, T data)
    {
        if (!current)
        {
            return current;
        }
        if (current->m_data == data)
        {
            auto removing = current;
            current = current->m_next;
            delete removing;
        }
        else
        {
            auto runner = current;
            while(runner->m_next)
            {
                if (runner->m_next->m_data == data)
                {
                    auto removing = runner->m_next;
                    runner->m_next = runner->m_next->m_next;
                    delete removing;
                    break;
                }
                else
                {
                    runner = runner->m_next;
                }
            }
        }
        return current;
    }

    node<T>* remove_all(node<T>* current, T data) // return new head
    {
        node<T>* result = current;
        while(current)
        {
            if(current->m_data == data)
            {
                result = current->m_next;
                auto removing = current;
                current = current->m_next;
                delete removing;
                continue;
            }
            auto runner = current;
            while(runner->m_next)
            {
                if (runner->m_next->m_data == data)
                {
                    auto removing = runner->m_next;
                    runner->m_next = runner->m_next->m_next;
                    delete removing;
                }
                else
                {
                    runner = runner->m_next;
                }
            }
            current = current->m_next;
        }
        return result;
    }

    node<T>* find_k_recursive(node<T>* current, const int k, int& i)
    {
        if (!current)
            return nullptr;
        auto n = find_k_recursive(current->m_next, k, i);
        i++;
        return i == k ? current : n;
    }

    node<T>* invert(node<T>* current)
    {
        if (!current->m_next)
        {
            return current;
        }
        else
        {
            auto head = invert(current->m_next);
            auto runner = head;
            while(runner->m_next)
            {
                runner = runner->m_next;
            }
            current->m_next = nullptr;
            runner->m_next = current;
            return head;
        }
    }
public:

    template<typename TI>
    class iterator
    {
        friend class linkedlist<TI>;

        node<T>* m_current;
        iterator(node<TI>* initial): m_current(initial) { }
    public:
        iterator& operator++()
        {
            if (m_current)
            {
                m_current = m_current->m_next;
            }
            return (*this);
        }

        bool operator!=(const iterator<TI>& other) const
        {
            return this->m_current != other.m_current;
        }

        const node<T>* operator*() const
        {
            return m_current;
        }

        operator bool() const
        {
            return m_current != nullptr;
        }

        node<TI>* operator->()
        {
            return m_current;
        }
    };

    linkedlist(): m_head(nullptr) { }
    ~linkedlist()
    {
        while(m_head)
        {
            auto tmp = m_head;
            m_head = m_head->m_next;
            delete tmp;
        }
    }

    void add(T data)
    {
        auto n = new node<T>{data, nullptr};
        if(m_head)
        {
            auto tmp = m_head;
            while(tmp->m_next)
            {
                tmp = tmp->m_next;
            }
            tmp->m_next = n;
        }
        else
        {
            m_head = n;
        }
    }

    void remove(T data)
    {
        m_head = remove(m_head, data);
    }

    void remove_all(T data)
    {
        m_head = remove_all(m_head, data);
    }


    void remove_all_duplicates()
    {
        if (!m_head)
        {
            return;
        }

        auto current = m_head;
        while(current)
        {
            auto runner = current->m_next;
            if (runner)
            {
                if (runner->m_data == current->m_data)
                {
                    auto removing = runner;
                    current->m_next = runner->m_next;
                    delete removing;
                    continue;
                }
                while(runner->m_next)
                {
                    if (runner->m_next->m_data == current->m_data)
                    {
                        auto removing = runner->m_next;
                        runner->m_next = runner->m_next->m_next;
                        delete removing;
                    }
                    else
                    {
                        runner = runner->m_next;
                    }
                }
            }
            current = current->m_next;
        }
    }

    void remove_all_duplicates2()
    {
        if (!m_head)
        {
            return;
        }

        auto current = m_head;
        while(current->m_next)
        {
            current->m_next = remove_all(current->m_next, current->m_data);
            current = current->m_next;
        }
    }

    void remove_all_duplicates3()
    {
        if (!m_head)
        {
            return;
        }

        auto current = m_head;
        std::unordered_set<T> uniques;
        node<T>* prev = nullptr;
        while(current)
        {
            if (uniques.find(current->m_data) != uniques.end())
            {
                auto removing = current;
                prev->m_next = current->m_next;
                current = current->m_next;
                delete removing;
            }
            else
            {
                uniques.insert(current->m_data);
                prev = current;
                current = current->m_next;
            }
        }
    }

    iterator<T> begin() const
    {
        return iterator<T>(m_head);
    }

    iterator<T> end() const
    {
        return iterator<T>(nullptr);
    }

    iterator<T> find_k(const int k)
    {
        auto e = end();
        auto fast = begin();
        int counter = 0;
        while(fast != e && counter < k)
        {
            ++fast;
            ++counter;
        }
        if (counter != k)
            return e;
        auto slow = begin();
        while(fast != e)
        {
            ++fast;
            ++slow;
        }
        return slow;
    }

    iterator<T> find_k_recursive(const int k)
    {
        int index = 0;
        iterator<T> it(find_k_recursive(m_head, k, index));
        return it;
    }

    void split_by(const T k)
    {
        node<T>* before = nullptr;
        node<T>* after = nullptr;

        int a = 0, b = 0;

        auto current = m_head;
        while(current)
        {
            auto next = current->m_next;
            if (current->m_data < k)
            {
                current->m_next = before;
                before = current;
                a++;
            }
            else
            {
                current->m_next = after;
                after = current;
                b++;
            }
            current = next;
        }

        std::cout << "[" << a << ", " << b << "] ";

        if (!before)
        {
            m_head = after;
        }
        else
        {
            m_head = before;
            while(before->m_next)
            {
                before = before->m_next;
            }
            before->m_next = after;
        }
    }

    void invert()
    {
        if (!m_head)
            return;
        m_head = invert(m_head);
    }

    friend std::ostream& operator<<(std::ostream& os, const linkedlist<T>& list)
    {
        for(auto p: list)
        {
            os  << p->m_data 
                // << "(" << p << ")" 
                << " -> ";
        }
        return (os << "null");
    }
};
