#include <iostream>

void insertSort(int* arr, const int count)
{
    for (int i = 0; i < count; ++i)
    {
        int min_value = arr[i];
        int min_index = i;
        for (int j = i + 1; j < count; ++j)
        {
            if (min_value > arr[j])
            {
                min_value = arr[j];
                min_index = j;
            }
        }
        int tmp = arr[i];
        arr[i] = min_value;
        arr[min_index] = tmp;
    }
}

int main()
{
    int nums[]{3, 4, 6, 2, 5, 8, 9, 0, 1, 7, 4};
    insertSort(nums, sizeof(nums)/sizeof(int));
    for(int i: nums)
    {
        std::cout << i << " ";
    }
    return 0;
}