#include <iostream>

void swap (int arr[], int idx1, int idx2)
{
    int tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
}

void print_array(int arr[], int cnt)
{
    for(int i=0; i<cnt; ++i)
        std::cout << arr[i] <<" ";
    std::cout << "\n";
}

//recursive solution
void selection_sort(int arr[], int start, int end)
{
    if (start < end - 1)
    {
        int min_idx = start;
        for(int i=start; i< end; ++i)
            if(arr[i] < arr[min_idx]) min_idx = i;

        swap(arr, start, min_idx);
        selection_sort(arr, start+1, end);
    }
}

int main()
{
    int arr[] = {3,7,6,1,8,2,5};
    int cnt = sizeof(arr)/sizeof(arr[0]);
    print_array(arr, cnt);
    selection_sort(arr, 0, cnt);
    print_array(arr, cnt);

    return 0;
}
