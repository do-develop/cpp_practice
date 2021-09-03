#include <iostream>

template<typename T>
void MergeSort(T arr[], int arrSize);

template<typename T>
void MergeSort(T arr[], T tmp[], int start, int last);

template<typename T>
void Merge(T arr[], T temp[], int start, int mid, int last);

//------------------------------------------------
int main()
{
    char arr[] = {'b', 'v', 't', 's', 'a', 'r', 'e', 'u', 'b'};
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort(arr, size);

    std::cout << "Sorted array: \n";
    for(int i=0; i<size; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    return 0;
}
//-------------------------------------------------

template<typename T>
void MergeSort(T arr[], int arrSize)
{
    T tmp[arrSize];
    MergeSort(arr, tmp, 0, arrSize-1);
}

template<typename T>
void MergeSort(T arr[], T tmp[], int start, int last)
{
    if(start < last)
    {
        int mid = (start + last) / 2;
        MergeSort(arr, tmp, start, mid);
        MergeSort(arr, tmp, mid+1, last);
        Merge(arr, tmp, start, mid, last);
    }
}

template<typename T>
void Merge(T arr[], T tmp[], int start, int mid, int last)
{
    for(int i = start; i <= last; ++i)
    {
        tmp[i] = arr[i];
    }
    int part1 = start;
    int part2 = mid + 1;
    int index = start;

    while(part1 <= mid && part2 <= last)
    {
        if(tmp[part1] <= tmp[part2])
        {
            arr[index] = tmp[part1];
            part1++;
        }
        else
        {
            arr[index] = tmp[part2];
            part2++;
        }
        index++;
        //left array has elements left
        for(int i=0; i<=mid-part1; ++i)
        {
            arr[index + i] = tmp[part1 + i];
        }
        //don't need to handle the case, where the right data is left to compare
    }
}
