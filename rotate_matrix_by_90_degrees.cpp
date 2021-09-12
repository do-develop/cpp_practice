#include <iostream>

const int arr_size = 5;

void rotateArray(int arr[][arr_size], int arr_size)
{
    int temp;

    for(int s=0, e=arr_size-1; s<e; s++, e--)
    {
        for(int i=s, j=e; i<e; i++, j--)
        {
            temp = arr[s][i];
            arr[s][i] = arr[i][e];
            arr[i][e] = arr[e][j];
            arr[e][j] = arr[j][s];
            arr[j][s] = temp;
        }
    }
}

void printArray(int arr[][arr_size], int arr_size)
{
    for(int i=0; i<arr_size; ++i)
    {
        for(int j=0; j<arr_size; ++j)
            std::cout << arr[i][j] << " ";
        std::cout << "\n";
    }
    std::cout << "\n";
}

int main()
{
    int arr[arr_size][arr_size] = {
        {1,0,0,0,1},
        {0,1,0,1,0},
        {0,0,1,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };

    printArray(arr,5);

    rotateArray(arr,5);
    printArray(arr,5);

    rotateArray(arr,5);
    printArray(arr,5);

    rotateArray(arr,5);
    printArray(arr,5);

    rotateArray(arr,5);
    printArray(arr,5);

    return 0;
}
