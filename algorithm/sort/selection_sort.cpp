#include <iostream>
#define MAX 1000
//Selection sort is very inefficient O(N^2)

int main(void)
{
    int min, index, temp;
    int arr[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
    for(int i=0; i<10; i++)
    {
        min=MAX;
        for(int j = i; j<10; j++)
        {
            if(min > arr[j])
            {
                min = arr[j];
                index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }

    for(int i=0; i<10; i++)
     {
         std::cout << arr[i] << " ";
     }
    return 0;
}
