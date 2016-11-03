#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <utility>

std::vector<std::string> sort_with_sort(std::vector<std::string> strings)
{
    std::sort(strings.begin(), strings.end(),
        [](std::string a, std::string b){ 
            std::sort(a.begin(), a.end());
            std::sort(b.begin(), b.end());
            return a < b;
        });
    return strings;
}

std::vector<std::string> sort_with_hash(std::vector<std::string> strings)
{
    std::unordered_map<std::string, std::vector<std::string>> hash;
    for (auto string: strings)
    {
        std::string sorted_string(string);
        std::sort(sorted_string.begin(), sorted_string.end());
        auto pos = hash.find(sorted_string);
        if (pos != hash.end())
        {
            pos->second.push_back(string);
        }
        else
        {
            hash[sorted_string] = std::vector<std::string>{string};
        }
    }
    std::vector<std::string> result;
    for(auto p: hash)
        result.insert(result.end(), p.second.begin(), p.second.end());
    return result;
}

int main()
{
    std::vector<std::string> sorting_strings{"c", "ab", "def", "efd", "ba", "fed"};

    auto ss = sort_with_sort(sorting_strings);
    for(auto s: ss) std::cout << s <<" ";
    std::cout << std::endl;

    auto sh = sort_with_hash(sorting_strings);
    for(auto s: sh) std::cout << s <<" ";
    return 0;
}