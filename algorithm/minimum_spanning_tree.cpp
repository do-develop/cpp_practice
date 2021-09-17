//To find minimum spanning tree of graph
//Kruskal algorithm
// 1. Sort all the edges in increasing order of their weight
// 2. Pick the smallest edge and check if it forms a cycle
//    If not, include this edge
// 3. Repeat step 2 until there are vertices -1 edges in the spanning tree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//to find parent
int getParent(int parent[], int x)
{
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]);
}

//to combine parents
int unionParent(int parent[], int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

//check find if the same parent
bool findParent(int parent[], int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a==b) return true;
    return false;
}

class Edge{

public:
    int node[2];
    int distance;

    Edge(int a, int b, int distance)
    {
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }

    bool operator < (Edge& edge)
    {
        return this->distance < edge.distance;
    }
};
int main(void)
{
    int node = 7;
    int edge = 11;

    vector<Edge> graph;
    graph.push_back(Edge(1, 7, 12));
    graph.push_back(Edge(1, 4, 28));
    graph.push_back(Edge(1, 2, 67));
    graph.push_back(Edge(1, 5, 17));
    graph.push_back(Edge(2, 4, 24));
    graph.push_back(Edge(2, 5, 60));
    graph.push_back(Edge(3, 5, 20));
    graph.push_back(Edge(3, 6, 37));
    graph.push_back(Edge(4, 7, 13));
    graph.push_back(Edge(5, 6, 45));
    graph.push_back(Edge(5, 7, 73));

    //sort the weight(distance)
    sort(graph.begin(), graph.end());

    //mst from graph
    int parent[node];
    for(int i=0; i<node; ++i)
        parent[i] = i;

    int sum = 0;
    for(int i=0; i<graph.size(); ++i)
    {
        //checking if cycle has formed
        if(!findParent(parent, graph[i].node[0]-1, graph[i].node[1]-1))
        {
            sum += graph[i].distance;
            unionParent(parent, graph[i].node[0]-1, graph[i].node[1]-1);
        }
    }

    printf("Sum: %d\n", sum);
}
