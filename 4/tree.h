#pragma once

#include <cmath>


template<typename T>
struct node
{
    T data;
    node<T>* left;
    node<T>* right;
};

template<typename T>
class tree
{
    node<T>* root = nullptr;

    bool isBalanced(node<T>* n, int& heght)
    {
        if (!n)
        {
            heght = 0;
            return true;
        }
        else
        {
            int lh, rh;
            bool lb = isBalanced(n->left, lh), rb = isBalanced(n->right, rh);
            heght = fmax(lh, rh) + 1;
            return lb && rb && fabs(lh - rh) <= 1;
        }
    }

public:

    bool isBalanced()
    {
        int heght = 0;
        return isBalanced(root, heght);
    }

};