#include <iostream>

int partition(int* arr, const int left, const int right)
{
    int pivot = arr[right - 1]; // can randomize
    int i = left;
    int j = right - 1;
    while(i < j)
    {
        while(arr[i] <= pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        if (i < j)
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    return i;
}
void quikSort(int* arr, const int left, const int right)
{
    if (left < right - 1)
    {
        int index = partition(arr, left, right);
        if (index < right) quikSort(arr, left, index);
        quikSort(arr, index, right);
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