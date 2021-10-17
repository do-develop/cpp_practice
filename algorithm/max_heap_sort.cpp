// O (n log n)

#include <iostream>

int count = 9;
int heap[9] = {7,6,5,8,3,5,9,1,6};

int main(void)
{
    //heapify the whole tree
    for(int i=1; i<count; i++)
    {
        int child = i;

        do
        {
            int parent = (child - 1)/2;
            if(heap[parent] < heap[child])
            {
                int temp = heap[parent];
                heap[parent] = heap[child];
                heap[child] = temp;
            }
            child = parent;
        } while (child != 0);
    }

    //sort
    for(int i=count-1; i>=0; i--)
    {
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;

        int parent = 0;
        int child = 1;
        do
        {
            child = 2*parent + 1;
            // if one of the child is bigger than the parent
            if(heap[child] < heap[child+1] && child < i-1)
            {
                child++;
            }
            //if child is bigger than the parent, switch
            if(heap[parent] < heap[child] && child < i)
            {
                int temp = heap[parent];
                heap[parent] = heap[child];
                heap[child] = temp;
            }
            parent = child;
        }while(child < i);
    }

    //print the result
    for(int i=0; i<count; i++)
    {
        std::cout << heap[i] << ' ';
    }
}
