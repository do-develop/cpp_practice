#include <iostream>

//find the parent node
int getParent(int parent[], int x)
{
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]);
}

//combine two parent nodes
int unionParent(int parent[], int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a<b) parent[b] = a;
    else parent[a] = b;
}

//check if you have the same parent
bool findParent(int parent[], int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a==b) return true;
    return false;
}

int main()
{
    int nodes[11];
    for(int i=1; i<11; ++i)
    {
        nodes[i] = i;
    }
    unionParent(nodes, 1, 2);
    unionParent(nodes, 2, 3);
    unionParent(nodes, 3, 4);
    unionParent(nodes, 5, 6);
    unionParent(nodes, 6, 7);
    unionParent(nodes, 7, 8);

    std::cout << "Is 1 and 5 connected? ";
    findParent(nodes, 1, 5);

    return 0;
}
