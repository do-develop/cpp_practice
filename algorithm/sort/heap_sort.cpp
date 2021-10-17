#include <iostream>

int node_count = 10;
int heap[10] = {7,2,6,5,8,3,5,9,1,7};

int main(void)
{
    //heapify
    //chage to max heap
    for(int i=1; i<node_count; ++i)
    {
        int child = i;
        do
        {
            int parent = (child-1)/2;
            if(heap[parent] < heap[child])
            {
                int temp = heap[parent];
                heap[parent] = heap[child];
                heap[child] = temp;
            }
            child = parent;
        } while (child != 0);
    }

    //To sort repeat next:
    //decrement the size and make max heap
    for(int i=node_count-1; i>=0; i--)
    {
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;

        int parent = 0;
        int child = 1;
        do
        {
            child = 2*parent + 1;
            //find bigger child
            if(heap[child] < heap[child+1] && child < i-1)
            {
                child++;
            }
            if(heap[parent] < heap[child] && child < i)
            {
                int temp = heap[parent];
                heap[parent] = heap[child];
                heap[child] = temp;
            }
            parent = child;
        } while(child < i);
    }

    //print heap sort result
    for(int i=0; i<node_count; ++i)
    {
        std::cout << heap[i] << ' ';
    }
}
