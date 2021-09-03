#ifndef DEQUE_LINKED_LIST_H_INCLUDED
#define DEQUE_LINKED_LIST_H_INCLUDED

template<class T>
struct node
{
    T data;
    node<T>* next;
};

template<class T>
class Deque
{
    public:
        Deque();
        ~Deque();

        void pushFront(const T& item);
        void pushBack(const T& item);
        void popFront();
        void popBack();

        T& peekFront() const;
        T& peekBack() const;
        int Size();

    private:
        int cnt;
        node<T>* head;
        node<T>* tail;
};

//----------------------------------------------
template<class T>
Deque<T>::Deque()
{
    head = nullptr;
    tail = nullptr;
    cnt = 0;
}

template<class T>
Deque<T>::~Deque()
{
    node<T>* temp;
    while(head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    //cnt = 0;
}

template<class T>
void Deque<T>::pushFront(const T& item)
{
   node<T>* newNode = new node<T>;
   newNode->data = item;
   newNode->next = nullptr;

   if(head==nullptr)
   {
       head = newNode;
       tail = newNode;
       cnt++;
   }
   else
   {
       newNode->next = head;
       head = newNode;
       cnt++;
   }
}

template<class T>
void Deque<T>::pushBack(const T& item)
{
    node<T>* newNode = new node<T>;
    newNode->data = item;
    newNode->next = nullptr;

    if(tail==nullptr)
    {
        head = newNode;
        tail = newNode;
        cnt++;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
        cnt++;
    }
}

template<class T>
void Deque<T>::popFront()
{
    if(head != nullptr)
    {
        node<T>* current = nullptr;
        current = head;
        head = head->next;
        delete(current);
        cnt--;
    }
}

template<class T>
void Deque<T>::popBack()
{
    if(tail==nullptr)
        return;
    if(head==tail)
    {
        head = nullptr;
        tail = nullptr;
        cnt--;
    }
    else
    {
        node<T>* current = head;
        while(current->next != tail)
        {
            current = current->next;
        }
        tail = current;
        tail->next = nullptr;
        cnt--;
    }
}

template<class T>
T& Deque<T>::peekFront() const
{
    if(head != nullptr)
    {
        return head->data;
    }
}

template<class T>
T& Deque<T>::peekBack() const
{
    if(tail != nullptr)
    {
        return tail->data;
    }
}

template<class T>
int Deque<T>::Size()
{
    return cnt;
}

#endif // DEQUE_LINKED_LIST_H_INCLUDED
