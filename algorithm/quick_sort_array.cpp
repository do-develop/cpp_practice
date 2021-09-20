#include <stdio.h>

void swapping(int arr[], int low, int high)
{
    int temp = arr[low];
    arr[low] = arr[high];
    arr[high] = temp;
}

//takes last element as pivot
//places all smaller to left
//all greater to right
int partition_array(int arr[], int low, int high)
{
    int pivot = arr[(low + high)/2];
    while(low <= high)
    {
        while(arr[low] < pivot) low++;
        while(arr[high] > pivot) high--;

        if(low <= high)
        {
            swapping(arr, low, high);
            low++;
            high--;
        }
    }
    return low;
}

void quick_sort(int arr[], int low, int high)
{
    int part2 = partition_array(arr, low, high);

    if(low < part2-1)
        quick_sort(arr, low, part2-1);

    if(part2 < high)
        quick_sort(arr, part2, high);
}

void quick_sort(int arr[], int cnt)
{
    quick_sort(arr, 0, cnt-1);
}

void print_array(int arr[], int cnt)
{
    for(int i=0; i<cnt; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {10, 7, 8, 3, 5, 9, 2, 6};
    int cnt = sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr, cnt);
    printf("Sorted array: \n");
    print_array(arr, cnt);

    return 0;
}
