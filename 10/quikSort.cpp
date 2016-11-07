#include <iostream>

void swap(int* arr, const int i, const int j)
{
    if (i == j)
    {
        return;
    }
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int partition(int* arr, const int left, const int right)
{
    int p = right - 1;
    int i = left - 1;
    for (int j = left; j < right - 1; ++j)
    {
        if (arr[j] <= arr[p])
        {
            ++i;
            swap(arr, i, j);
        }
    }
    ++i;
    swap(arr, i, right - 1);
    return i;
}
void quikSort(int* arr, const int left, const int right)
{
    if (left < right - 1)
    {
        int index = partition(arr, left, right);
        quikSort(arr, left, index);
        quikSort(arr, index + 1, right);
    }
}

int main()
{
    int nums[]{3, 4, 1, 4, 6, 2, 5, 8, 9, 0, 1, 7, 4};
    quikSort(nums, 0, sizeof(nums)/sizeof(nums[0]));
    for(int i: nums)
    {
        std::cout << i << " ";
    }
    return 0;
}