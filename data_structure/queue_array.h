#ifndef QUEUE_ARRAY_H_INCLUDED
#define QUEUE_ARRAY_H_INCLUDED

const int SIZE = 10;

template<class T>
class Queue
{
public:
    Queue();
    ~Queue();

    bool Join(const T& item);
    bool Leave(T& item);
    T& Front();

    bool Empty();
    bool Full();
    int Size();

private:
    T* arr;
    int head;
    int tail;
    int cnt;
};

template<class T>
Queue<T>::Queue()
{
    arr = new T[SIZE];
    cnt = 0;
    head = 0;
    tail = -1;
}

template<class T>
Queue<T>::~Queue()
{
    delete[] arr;
}

template<class T>
bool Queue<T>::Join(const T& item) //enqueue
{
    bool isAdded = false;

    if(cnt != SIZE)
    {
        tail = (tail+1)%SIZE; //circular implementation
        arr[tail] = item;
        cnt++;
        isAdded = true;
    }
    return isAdded;
}

template<class T>
bool Queue<T>::Leave(T& item)
{
    bool isRemoved = false;

    if(cnt != 0)
    {
        item = arr[head];
        head = (head+1)%SIZE;
        cnt--;
        isRemoved = true;
    }
    return isRemoved;
}

template<class T>
T& Queue<T>::Front()
{
    if(cnt != 0)
        return arr[head];
}


template<class T>
bool Queue<T>::Empty()
{
    return (cnt==0);
}

template<class T>
bool Queue<T>::Full()
{
    return (cnt==SIZE);
}
template<class T>
int Queue<T>::Size()
{
    return cnt;
}

#endif // QUEUE_ARRAY_H_INCLUDED
