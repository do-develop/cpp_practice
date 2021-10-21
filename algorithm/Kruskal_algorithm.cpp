//how to connect node with minimum cost(distance)?
//minimum edge count = node count - 1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getParent(int parent[], int x)
{
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]);
}

int unionParent(int parent[], int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

bool isSameParent(int parent[], int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a==b) return true;
    return false;
}

class Edge
{
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
    int node_count = 7;
    int edge_count = 11;

    vector<Edge> graph;
    graph.push_back(Edge(1, 7, 12));
    graph.push_back(Edge(1, 4, 28));
    graph.push_back(Edge(1, 2, 67));
    graph.push_back(Edge(1, 5, 17));
    graph.push_back(Edge(2, 4, 24));
    graph.push_back(Edge(2, 5, 62));
    graph.push_back(Edge(3, 5, 20));
    graph.push_back(Edge(3, 6, 37));
    graph.push_back(Edge(4, 7, 13));
    graph.push_back(Edge(5, 6, 45));
    graph.push_back(Edge(5, 7, 73));

    //distance value in ascending order
    sort(graph.begin(), graph.end());

    //save the graph that includes the node
    int parent[node_count];
    for(int i=0; i<node_count; ++i)
    {
        parent[i] = i;
    }

    int distance_sum = 0;
    for(int i=0; i<graph.size(); i++)
    {
        //if no cycle then include this into the graph
        if(!isSameParent(parent, graph[i].node[0] - 1, graph[i].node[1] - 1))
        {
            distance_sum += graph[i].distance;
            unionParent(parent, graph[i].node[0] - 1, graph[i].node[1] -1);
        }
    }
    printf("Total distance: %d\n", distance_sum);

    return 0;
}
