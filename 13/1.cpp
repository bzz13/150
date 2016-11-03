#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <list>

std::list<std::string> get_last_k_lines(const std::string& filename, const int count)
{
    std::list<std::string> result;
    std::ifstream fin(filename.c_str(), std::ifstream::in);
    while(!fin.eof())
    {
        std::string line;
        getline(fin, line);
        result.push_back(line);
        if(result.size() > count)
            result.pop_front();
    }
    fin.close();
    return result;
}

void print_last_k_lines(const std::string filename, const int count, std::ostream& os = std::cout)
{
    auto last_k_lines = get_last_k_lines(filename, count);
    for (auto line: last_k_lines)
    {
        os << line << std::endl;
    }
}

int main()
{
    std::string filename("1.cpp");
    print_last_k_lines(filename, 5);
    return 0;
}