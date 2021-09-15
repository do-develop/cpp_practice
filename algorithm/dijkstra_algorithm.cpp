#include <iostream>
#include <climits>
using namespace std;

const int node_count = 6;

//find minimum distance
int mini_dist_idx(int distance[], bool visit[])
{
    int minimum = INT_MAX;
    int idx;

    for(int i=0; i<node_count; ++i)
    {
        if(visit[i]==false && distance[i]<=minimum)
        {
            minimum = distance[i];
            idx = i;
        }
    }
    return idx;
}
int print_solution(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < node_count; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[node_count][node_count], int start)
{
    int distance[6] = {INT_MAX}; //to store minimum distance for each node
    bool visit[6] = {false}; //to mark visited node

    for (int i = 0; i < node_count; i++)
        distance[i] = INT_MAX, visit[i] = false;

    // Distance of source vertex from itself is always 0
    distance[start] = 0;

    // Find shortest path for all vertices
    for(int i=0; i<node_count-1; ++i)
    {
        int current = mini_dist_idx(distance, visit);
        // Mark the picked vertex as processed
        visit[current] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for(int j=0; j<node_count; j++)
        {
            if(!visit[j] && graph[current][j] &&
               distance[current]!=INT_MAX &&
               distance[current]+graph[current][j] < distance[j])
            {
                distance[j] = distance[current] + graph[current][j];
            }
        }
    }

    print_solution(distance, node_count);

}

int main()
{
    int graph[node_count][node_count]=
        {
        {0, 1, 2, 0, 0, 0},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 0, 2, 1, 0}};

    dijkstra(graph, 0);

    return 0;
}
