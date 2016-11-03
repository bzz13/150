#include <iostream>

void bubleSort(int* arr, const int count)
{
    for (int i = 0; i < count; ++i)
    {
        for (int j = i + 1; j < count; ++j)
        {
            if (arr[i] > arr[j])
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int main()
{
    int nums[]{3, 4, 6, 2, 5, 8, 9, 0, 1, 7, 4};
    bubleSort(nums, sizeof(nums)/sizeof(int));
    for(int i: nums)
    {
        std::cout << i << " ";
    }
    return 0;
}