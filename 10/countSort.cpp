#include <iostream>

void countSort(int* arr, const int size)
{
    int k = 0;
     for (int i = 0; i < size; ++i)
        if(arr[i] > k)
            k = arr[i];
    ++k;

    int* c = new int[k];
    int* b = new int[size];

    for (int i = 0; i < k; ++i)
        c[i] = 0;

    for (int i = 0; i < size; ++i)
        c[arr[i]]++;

    for (int i = 1; i < k; ++i)
        c[i] += c[i - 1];

    for (int i = size - 1; i >= 0; --i)
    {
        b[c[arr[i]] - 1] = arr[i];
        c[arr[i]] --;
    }

    for (int i = 0; i < size; ++i)
        arr[i] = b[i];

    delete[] c;
    delete[] b;
}

int main()
{
    int nums[]{3, 4, 1, 4, 6, 2, 5, 8, 9, 0, 1, 7, 4};
    for(int i: nums)
        std::cout << i << " ";
    std::cout << std::endl;
    countSort(nums, sizeof(nums)/sizeof(nums[0]));
    for(int i: nums)
        std::cout << i << " ";

    return 0;
}