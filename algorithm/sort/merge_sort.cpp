#include <iostream>
//Merge sort O(nlogn)

const int count = 8;
int sorted[count];

void merge(int a[], int start, int mid, int end)
{
    int left = start;
    int right = mid + 1;
    int sort = start; //sorted position

    while(left <= mid && right <= end)
    {
        if(a[left] <= a[right])
        {
            sorted[sort] = a[left];
            left++;
        } else {
            sorted[sort] = a[right];
            right++;
        }
        sort++;
    }
    //leftovers
    if(left > mid)
    {
        for(int i = right; i <= end; i++)
        {
            sorted[sort] = a[i];
            sort++;
        }
    }
    else
    {
        for(int i = left; i <= mid; i++)
        {
            sorted[sort] = a[i];
            sort++;
        }
    }
    //insert the sorted array
    for(int i=start; i<=end; i++)
    {
        a[i] = sorted[i];
    }
}

int merge_sort(int a[], int start, int end)
{
    if(start < end)
    {
        int mid = (start + end) / 2;
        merge_sort(a, start, mid);
        merge_sort(a, mid+1, end);
        merge(a, start, mid, end);
    }
}

int main(void)
{
    int arr[count] = {7,6,5,8,3,5,9,1};
    merge_sort(arr, 0, count-1);
    for(int i=0; i<count; ++i)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
