#include "tree.h"
#include <iostream>

int main()
{
    tree<int> t;
    std::cout << t.isBalanced() << std::endl;
    return 0;
}