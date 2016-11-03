#include <iostream>

int partition(int* arr, const int left, const int right)
{
    int pivot = arr[right - 1];
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
    if (left < right)
    {
        int index = partition(arr, left, right);
        if (left < index && index < right) quikSort(arr, left, index);
        if (index < right - 1) quikSort(arr, index, right);
    }
}

int main()
{
    int nums[]{3, 4, 6, 2, 5, 8, 9, 0, 1, 7, 4};
    quikSort(nums, 0, sizeof(nums)/sizeof(nums[0]));
    for(int i: nums)
    {
        std::cout << i << " ";
    }
    return 0;
}