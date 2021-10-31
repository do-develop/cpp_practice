#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

const int MAX = 10;

template<class T>
class Stack
{
    private:
        T* arr; // use heap memory
        int top; // position of the lastest element in the array
    public:
        Stack();
        ~Stack();

        bool Push(T data);
        bool Pop(T& data);
        bool Empty();
};

template<class T>
Stack<T>::Stack()
{
    arr = new T[MAX];
    top = -1;
}

template<class T>
Stack<T>::~Stack()
{
    delete[] arr;
}

template<class T>
bool Stack<T>::Push(T data)
{
    if(top >= (MAX-1)) //check overflow
        return false;
    else
    {
        arr[++top] = data;
        return true;
    }
}

template<class T>
bool Stack<T>::Pop(T& data)
{
    if(top < 0) //check underflow
        return false;
    else
    {
        data = arr[top--];
        //--top;
        return true;
    }
}

template<class T>
bool Stack<T>::Empty()
{
    return (top < 0);
}
#endif // STACK_H_INCLUDED
