#include <iostream>

void merge(int* arr, int left, int middle, int right)
{
    int* copy = new int[right - left];
    for (int i = left; i < right; ++i)
    {
        copy[i - left] = arr[i];
    }

    int l = left;
    int r = middle;
    int c = left;
    while(l < middle && r < right)
    {
        if(copy[l - left] < copy[r - left])
        {
            arr[c] = copy[l - left];
            l++;
        }
        else
        {
            arr[c] = copy[r - left];
            r++;
        }
        c++;
    }
    while(l < middle)
    {
        arr[c] = copy[l - left];
        l++;
        c++;
    }

    delete[] copy;
}

void mergeSort(int* arr, const int left, const int right)
{
    if (left < right)
    {
        int middle = (left + right) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left - 1, middle, right);
    }
}


int main()
{
    int nums[]{3, 4, 6, 2, 5, 8, 9, 0, 1, 7};//, 4};
    mergeSort(nums, 1, sizeof(nums)/sizeof(int));
    for(int i: nums)
    {
        std::cout << i << " ";
    }
    return 0;
}