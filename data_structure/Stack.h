#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

const int MAX = 10;

template<class T>
class Stack
{
    public:
        Stack();
        ~Stack();

        bool Push(T data);
        bool Pop(T& data);
        T& Top(); //peek
        int Size();
        bool IsEmpty();

    private:
        T* arr; //going to use heap memory
        int top; //position of the latest element in the array
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
    if(top >= (MAX-1))
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
    if(top < 0)
        return false;
    else
    {
        data = arr[top];
        --top;
        return true;
    }
}

template<class T>
T& Stack<T>::Top()
{
    if(top != -1)
        return arr[top];
}

template<class T>
int Stack<T>::Size()
{
    return top+1; //array starts from 0
}

template<class T>
bool Stack<T>::IsEmpty()
{
    return (top < 0);
}




#endif // STACK_H_INCLUDED
