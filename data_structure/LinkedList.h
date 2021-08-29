#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

template<class T>
class Node
{
    public:
        Node();
        ~Node();

        Node<T>* GetNext();
        void SetNext(Node* next);

        T& GetData();
        void SetData(const T& data);

    private:
        T m_data;
        Node<T>* m_next;
};

template<class T>
Node<T>::Node()
{
    m_next = nullptr;
}

template<class T>
Node<T>::~Node(){}

template<class T>
Node<T>* Node<T>::GetNext()
{
    return m_next;
}

template<class T>
void Node<T>::SetNext(Node* next)
{
    m_next = next;
}

template<class T>
T& Node<T>::GetData()
{
    return m_data;
}

template<class T>
void Node<T>::SetData(const T& data)
{
    m_data = data;
}

template<class T>
class LinkedList
{
    public:
        LinkedList();
        ~LinkedList();

        void Add(T item);
        bool Delete(const T& item);
        int Find(const T& item);
        T& Get(int index);
        int Size();

    private:
        Node<T>* head;
        Node<T>* tail;
        int cnt;

};

template<class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    cnt = 0;
}

template<class T>
LinkedList<T>::~LinkedList()
{
    Node<T>* temp;

    while(head!=nullptr)
    {
        temp = head;
        head = head->GetNext();
        delete temp;
    }
    tail = nullptr;
}

template<class T>
void LinkedList<T>::Add(T item)
{
    Node<T>* newNode = new Node<T>;
    newNode->SetData(item);
    newNode->SetNext(nullptr);
    if(head==nullptr)
    {
        head = newNode;
        tail = newNode;
        cnt++;
    }
    else
    {
        tail->SetNext(newNode);
        tail = tail->GetNext();
        cnt++;
    }
}

template<class T>
bool LinkedList<T>::Delete(const T& item)
{
    bool found = false;
    Node<T>* temp;

    //if the item is found from the first and the only node
    if(head->GetData()==item && head==tail)
    {
        found = true;
        temp = head;
        head = tail = nullptr;
        delete temp;
        cnt--;
    }
    //if the item is found from the first node but it is not the only node
    else if(head->GetData()==item && head->GetNext()!=nullptr)
    {
        found = true;
        temp = head;
        head = head->GetNext();
        delete temp;
        cnt--;
    }
    else //item is not found from the first node
    {
        //two nodes will be used to find the matching node
        Node<T>* current = head;
        Node<T>* trailCurrent = nullptr;

        //while not found and the tracking reached the end of the list
        while(current!=nullptr && !found)
        {
            if(current->GetData()==item)
            {
                found = true;
                temp = current;
                trailCurrent->SetNext(current->GetNext()); //link the previous node to the next next node
                delete temp;
                current = nullptr; //handle dangling pointer
                cnt--;
            }
            else
            {
                trailCurrent = current;
                current = current->GetNext();
            }
        }//end of while
    }
    return found; //item was found and deleted
}

template<class T>
int LinkedList<T>::Find(const T& item)
{
    Node<T>* current = head;
    int index = 0;
    while(current != nullptr)
    {
        if(current->GetData()==item)
        {
            return index;
        }
        current = current->GetNext();
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
        current = current->GetNext();
    }
    return current->GetData();
}

template<class T>
int LinkedList<T>::Size()
{
    return cnt;
}

#endif // LINKEDLIST_H_INCLUDED
