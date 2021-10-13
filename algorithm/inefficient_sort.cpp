#include <iostream>

//worst - bubble sort O(N^2)
void bubble_sort(int * arr)
{
    int temp;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<9-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

//not much better - insertion sort O(N^2)
//but swap is done only when needed (better than selection or bubble sort
void insertion_sort(int* arr)
{
    int temp;
    int j;
    for(int i=0; i<9; i++)
    {
        j = i;
        while(arr[j] > arr[j+1])
        {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            j--;
        }
    }
}

int main(void)
{
    int arr[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

    insertion_sort(arr);

    for(int i=0; i<10; i++)
    {
        std::cout << arr[i] << ' ';
    }
    return 0;
}
