#include <iostream>

class ref_counter
{
    int m_count = 0;
public:
    int count() const
    {
        return m_count;
    }

    void add_ref()
    {
        ++m_count;
    }

    int release_ref()
    {
        return --m_count;
    }
};

template<typename T>
class smart_ptr
{
    T*              m_ptr;
    ref_counter*    m_counter;
    bool            m_released = false;
public:
    smart_ptr(T* ptr = nullptr): m_ptr(ptr), m_counter(nullptr)
    {
        if (m_ptr)
        {
            m_counter = new ref_counter();
            m_counter->add_ref();
        }
    }
    smart_ptr(smart_ptr<T>& other): m_ptr(other.m_ptr), m_counter(other.m_counter)
    {
        if (m_ptr)
        {
            m_counter->add_ref();
        }
    }

    void release()
    {
        if(m_counter)
        {
            auto remaning = m_counter->release_ref();
            std::cout << "remaning refs for " << m_ptr << ": " << remaning << std::endl;
            if (remaning == 0)
            {
                delete m_ptr;
                delete m_counter;
            }
            m_released = true;
        }
    }
    ~smart_ptr()
    {
        if (!m_released)
            release();
    }

    smart_ptr<T>& operator=(const smart_ptr<T>& other)
    {
        if (this != &other)
        {
            if (m_ptr && m_ptr != other.m_ptr)
            {
                release();
            }
            m_released = false;
            m_ptr = other.m_ptr;
            m_counter = other.m_counter;
            if (other.m_ptr)
            {
                m_counter->add_ref();
            }
        }
        return *this;
    }

    operator bool()
    {
        return !m_released && m_ptr && m_counter && m_counter->count();
    }

    T* operator->()
    {
        return (*this) ? m_ptr : nullptr;
    }

    T& operator*()
    {
        if (*this)
        {
            return *m_ptr;
        }
        throw "already released";
    }
};

int main()
{
    {
        smart_ptr<int> p1(new int(6));
        smart_ptr<int> p2(p1);
        smart_ptr<int> p3;
        smart_ptr<int> p4;
        p3 = p1;

        std::cout << "*p3: " << *p3 << std::endl;

        std::cout << "p3.release(): ";
        p3.release();
        try
        {
            std::cout << "try * released p3" << std::endl;
            std::cout << *p3 << std::endl;
        }
        catch(const char* what)
        {
            std::cout << "catch exception: " << what << std::endl;
        }

        std::cout << "p2 = p2: no effects" << std::endl;
        p2 = p2;

        std::cout << "p2 = p4: ";
        p2 = p4;

        smart_ptr<int> p5(new int(3));
        std::cout << "p2 = p5: no release couse p2 was = p4(nullptr)" << std::endl;
        p2 = p5;

        std::cout << "p5.release(): ";
        p5.release();

        std::cout << "~smart_ptr:" << std::endl;
    }
    return 0;
}