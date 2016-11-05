#include <mutex>
#include <thread>
#include <memory>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <sstream>

class chop_stick
{
    std::mutex m_mtx;
public:
    void take()
    {
        m_mtx.lock();
    }

    void put_down()
    {
        m_mtx.unlock();
    }
};

class philosopher
{
    chop_stick* m_left;
    chop_stick* m_right;
    bool        m_is_hangry = true;
public:
    philosopher(chop_stick* leff, chop_stick* right)
        :m_left(leff), m_right(right)
    {
    }

    void eat()
    {
        while(m_is_hangry)
        {
            m_left->take();
            std::this_thread::sleep_for(std::chrono::milliseconds(rand()% 5000));
            m_right->take();
            std::this_thread::sleep_for(std::chrono::milliseconds(rand()% 5000));
            std::stringstream answer;
            answer << std::this_thread::get_id() << ": Я покушал!" << std::endl;
            std::cout << answer.str();
            m_is_hangry = false;
            m_left->put_down();
            m_right->put_down();
        }
    }
};

int main()
{
    const int max = 10;
    chop_stick sticks[max];
    std::vector<philosopher> ph;

    for(int i = 0; i < max; ++i)
    {
        ph.push_back(philosopher(&sticks[i], &sticks[(i+1)%max]));
    }

    std::vector<std::thread> ths;
    for(int i = 0; i < max; ++i)
    {
        ths.push_back(std::thread([&ph, &i](){
            ph[i].eat();
        }));
    }

    for(auto& t: ths)
    {
        if (t.joinable())
        {
            t.join();
        }
    }

    return 0;
}