//O(NlogN)
#include <iostream>


void quick_sort(int* data, int start, int last)
{
    if(start >= last) //only have one element
        return;

    int pivot = start; //first element value is the pivot value
    int bigger = start + 1;
    int smaller = last;
    int temp;

    while(bigger <= smaller) //until the smaller value is on the left side of bigger value
    {
        while(data[bigger] <= data[pivot]) //move right until it meets the bigger value than the pivot value
        {
            bigger++;
        }
        while(data[smaller] >= data[pivot]
              && smaller > start )//move left until it meets the smaller value
        {
            smaller--;
        }
        if(bigger > smaller) //already in sorted position
        {// then switch the smaller value with the pivot value
            temp = data[smaller];
            data[smaller] = data[pivot];
            data[pivot] = temp;
        }
        else
        {// if not switch the smaller value with the bigger value
            temp = data[smaller];
            data[smaller] = data[bigger];
            data[bigger] = temp;
        }
    }

    quick_sort(data, start, smaller-1);
    quick_sort(data, smaller+1, last);
}

int main(void)
{
    int data_count = 10;
    int data[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

    quick_sort(data, 0, data_count-1); //index 0 to 9

    //print the sorted result
    for(int i=0; i<data_count; ++i)
    {
        std::cout << data[i] << ' ';
    }
    return 0;
}
