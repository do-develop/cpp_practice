#include <iostream>

using namespace std;

int node_count = 15;

typedef struct node *treePointer;
typedef struct node {
    int data;
    treePointer leftChild, rightChild;
} node;


void preorder(treePointer ptr)
{
    if(ptr)
    {
        cout << ptr->data << ' ';
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}

void inorder(treePointer ptr)
{
    if(ptr)
    {
        inorder(ptr->leftChild);
        cout << ptr->data << ' ';
        inorder(ptr->rightChild);
    }
}

void postorder(treePointer ptr)
{
    if(ptr)
    {
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        cout << ptr->data << ' ';
    }
}

int main(void)
{
    node tree[node_count+1];

    for(int i=1; i <= node_count; ++i)
    {
        tree[i].data = i;
        tree[i].leftChild = nullptr;
        tree[i].rightChild = nullptr;
    }

    for(int i=1; i <= node_count; ++i)
    {
        if(i%2 == 0)
        {
            tree[i/2].leftChild = &tree[i];
        }
        else
        {
            tree[i/2].rightChild = &tree[i];
        }
    }

    //preorder(&tree[1]);
    //inorder(&tree[1]);
    postorder(&tree[1]);
    return 0;
}
