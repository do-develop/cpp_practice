#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
//Topic 6, Lec-17, page 11-19
template<class T>
struct Node
{
    T m_data;
    Node<T>* m_next;
};

template<class T>
class LinkedList
{
    public:
        LinkedList();
        ~LinkedList();

        void Add(T item, int index);
        bool Delete(int index);
        int Find(const T& item);
        T& Get(int index);
        int Size();

    private:
        Node<T>* head;
        int cnt;

};

template<class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    cnt = 0;
}

template<class T>
LinkedList<T>::~LinkedList()
{
    Node<T>* temp;

    while(head!=nullptr)
    {
        temp = head;
        head = head->m_next;
        delete temp;
    }
}

template<class T>
void LinkedList<T>::Add(T item, int index)
{
    Node<T>* newNode = new Node<T>;
    newNode->m_data = item;
    newNode->m_next = nullptr;
    if(index==0)
    {
        if(head!=nullptr)
            newNode->m_next = head;
        //move head to new node
        head = newNode;
        cnt++;
    }
    else//insert in the middle of the linked list
    {
        Node<T>* temp = head;
        for(int i=0; i<index-1; ++i)
        {
            if(temp->m_next != nullptr)
                temp = temp->m_next;
        }
        newNode->m_next = temp->m_next;
        temp->m_next = newNode;
        cnt++;
    }
}

template<class T>
bool LinkedList<T>::Delete(int index)
{
    Node<T>* temp = head;
    bool isDeleted = false;

    //if the item is found from the first and the only node
    if(index==0)
    {
        if(head->m_next!=nullptr)
            head = head->m_next;
        else
            head = nullptr;
        delete temp;
        cnt--;
        isDeleted = true;
    }
    else //item is not found from the first node
    {
        //two nodes will be used to find the matching node
        Node<T>* current = head;
        Node<T>* trailCurrent = nullptr;
        for(int i=0; i<index; ++i)
        {
            if(current->m_next != nullptr)
            {
                trailCurrent = current;
                current = current->m_next;
            }

        }
        temp = current;
        trailCurrent->m_next = current->m_next;
        delete temp;
        current = nullptr; //handle dangling pointer
        cnt--;
        isDeleted = true;
    }
    return isDeleted;
}

template<class T>
int LinkedList<T>::Find(const T& item)
{
    Node<T>* current = head;
    int index = 0; //it is going to return negative value when not found
    while(current != nullptr)
    {
        if(current->m_data==item)
        {
            return index;
        }
        current = current->m_next;
        index++;
    }
    return -1;
}

template<class T>
T& LinkedList<T>::Get(int index)
{
    Node<T>* current = head;
    for(int i=0; i<index; ++i)
    {
        current = current->m_next;
    }
    return current->m_data;
}

template<class T>
int LinkedList<T>::Size()
{
    return cnt;
}

#endif // LINKEDLIST_H_INCLUDED
