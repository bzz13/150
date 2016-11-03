#include <iostream>

void merge(int* a, const int size_a, int* b, const int size_b)
{
    if (size_a < size_b)
        throw "too small";
    int i_a = size_a - size_b - 1;
    int i_b = size_b - 1;
    int pos = size_a - 1;
    while(i_b > -1 && i_a > -1)
    {
        if(b[i_b] >= a[i_a])
        {
            a[pos] = b[i_b];
            i_b--;
        }
        else
        {
            a[pos] = a[i_a];
            i_a--;
        }
        pos--;
    }
    while(i_b > -1)
    {
        a[pos] = b[i_b];
        i_b--;
        pos--;
    }
}

int main()
{
    int a[]{2, 5, 7, 8, -1, -1 , -1};
    int b[]{3,4,9};
    merge(a, 7, b, 3);
    for(auto el: a)
    {
        std::cout << el <<" ";
    }
    return 0;
}