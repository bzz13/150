#include <iostream>
#include <unordered_map>
#include <stdexcept>
#include <vector>

int median(const int a, const int b, const int c)
{
    if (a <= b && b <= c){
        return b;
    }
    if (a <= c && c <= b){
        return c;
    }
    if (b <= a && a <= c){
        return a;
    }
    if (b <= c && c <= a){
        return c;
    }
    if (c <= a && a <= b){
        return a;
    }
    if (c <= b && b <= a){
        return b;
    }
}


struct TNode {
    TNode* left;
    TNode* right;
    int value;
};


class R {
    std::unordered_map<int, int> values;
    
    void precalc(TNode* node, const int level)
    {
        if (!node)
        {
            return;
        }
        if(values.find(level) == values.end())
        {
            values[level] = node->value;
        }
        else
        {
            values[level] += node->value;
        }
        precalc(node->left, level+1);
        precalc(node->right, level+1);
    }
public:
    R(TNode* root)
    {
        precalc(root, 0);
    }
    int request(int r)
    {
        if (values.find(r) != values.end())
        {
            return values[r];
        }
        throw std::runtime_error("level not exists");
    }
};


template<typename T>
void blend(std::vector<T>& source, const std::vector<T>& extra, const std::vector<int>& pos) {
    // source: [12, 23]
    // extra: [42, 1, 53]
    // pos:   [0, 0, 5]
    // [1, 42, 12, 23, 53]
        
    if (extra.size() != pos.size())
    {
        throw std::runtime_error("extra.size() != pos.size()");
    }
    std::unordered_map<int, std::vector<int>> pos_values;
    for(int i = 0; i < pos.size(); ++i)
    {
        if (pos[i] < 0)
        {
            throw std::runtime_error("index is negative");
        }
        if (pos_values.find(pos[i]) == pos_values.end())
        {
            pos_values[pos[i]] = std::vector<T>{extra[i]};
        }
        else
        {
            pos_values[pos[i]].push_back(extra[i]);
        }
    }
    std::vector<T> result(source);
    result.insert(result.end(), extra.begin(), extra.end());

    auto current = source.begin();
    for(int i = 0; i < result.size(); ++i)
    {
        if (pos_values.find(i) != pos_values.end())
        {
            int j = i;
            for(auto tmp = pos_values[i].rbegin(); tmp != pos_values[i].rend(); ++tmp)
            {
                result[j] = *tmp;
                ++j;
            }
            i = j - 1;
        }
        else
        {
            result[i] = *current;
            current++;
        }
    }
    source.swap(result);

    /*
    auto insert_position = source.begin();
    for (int i = 0; i < pos.size(); ++i)
    {
        if (pos[i] < 0)
        {
            throw std::runtime_error("index is negative");
        }
        source.insert(insert_position + pos[i], extra[i]);
    }
    */
}  


int main()
{
    TNode* root = 
        new TNode{
            new TNode{
                nullptr, 
                nullptr, 
                2}, 
            new TNode{
                nullptr, 
                new TNode{
                    nullptr, 
                    nullptr, 
                    7}, 
                1}, 
            4};
    
    R r(root);
    std::cout << (r.request(0) == 4) << std::endl;
    std::cout << (r.request(1) == 3) << std::endl;
    std::cout << (r.request(2) == 7) << std::endl;
    try
    {
        r.request(3);
    }
    catch(const char* what)
    {
        std::cout << what << std::endl;
    }
    
    
    std::vector<int> s{12, 23};
    std::vector<int> e{42, 1, 53};
    std::vector<int> p{0, 0, 3};
    
    blend(s, e, p);
    for(int i: s)
    {
        std::cout << i << " ";
    }
    return 0;
}