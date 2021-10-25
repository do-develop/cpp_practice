#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int node_count = 6;
const int INF = 1000000000;

vector<pair<int, int>> graph[7];
int d[7];

void dijkstra(int start)
{
    d[start] = 0;
    priority_queue<pair<int, int>> pq; //max heap structure
    pq.push(make_pair(start, 0));

    while(!pq.empty())
    {
        int current = pq.top().first;
        //to make it min heap structure make numbers negative
        int distance = -pq.top().second;
        pq.pop();
        //if it is not the min distance, skip
        if(d[current] < distance) continue;
        for(int i=0; i<graph[current].size(); ++i)
        {
            int next = graph[current][i].first;
            int nextDistance = distance + graph[current][i].second;
            if(nextDistance < d[next])
            {
                d[next] = nextDistance;
                pq.push(make_pair(next, -nextDistance));
            }
        }
    }
}
/*
//initialise the graph
int graph[6][6] = {
    {0, 2, 5, 1, INF, INF},
    {2, 0, 3, 2, INF, INF},
    {5, 3, 0, 3, 1, 5},
    {1, 2, 3, 0, 1, INF},
    {INF, INF, 1, 1, 0, 2},
    {INF, INF, 5, INF, 2, 0}
};

int getMinCostIndex()
{
     int min = INF;
     int index = 0;
     for(int i=0; i<node_count; i++)
     {
         if(distance[i]<min && !visited[i])
         {
             min = distance[i];
             index = i;
         }
     }
     return index;
}

void dijkstra(int start)
{
    //initialise distance
    for(int i=0; i<node_count; ++i)
    {
        distance[i] = graph[start][i];
    }
    visited[start] = true;
    for(int i=0; i<node_count-2; i++) //node_count-2 (to minus itself and the last node)
    {
        int current = getMinCostIndex();
        visited[current] = true;
        for(int j=0; j<6; ++j)
        {
            if(!visited[j])
                if(distance[current] + graph[current][j] < distance[j])
                    distance[j] = distance[current] + graph[current][j];
        }
    }
}
*/

int main(void)
{
    for(int i=1; i<=node_count; ++i)
    {
        d[i] = INF;
    }

    graph[1].push_back(make_pair(2,2));
    graph[1].push_back(make_pair(3,5));
    graph[1].push_back(make_pair(4,1));

    graph[2].push_back(make_pair(1,2));
    graph[2].push_back(make_pair(3,3));
    graph[2].push_back(make_pair(4,2));

    graph[3].push_back(make_pair(1,5));
    graph[3].push_back(make_pair(2,3));
    graph[3].push_back(make_pair(4,3));
    graph[3].push_back(make_pair(5,1));
    graph[3].push_back(make_pair(6,5));

    graph[4].push_back(make_pair(1,1));
    graph[4].push_back(make_pair(2,2));
    graph[4].push_back(make_pair(3,3));
    graph[4].push_back(make_pair(5,1));

    graph[5].push_back(make_pair(3,1));
    graph[5].push_back(make_pair(4,1));
    graph[5].push_back(make_pair(6,2));

    graph[6].push_back(make_pair(3,5));
    graph[6].push_back(make_pair(5,2));

    dijkstra(1);

    for(int i=1; i<=node_count; ++i)
        cout << d[i] << " ";

    //answer: 0 2 3 1 2 4

    return 0;
}
