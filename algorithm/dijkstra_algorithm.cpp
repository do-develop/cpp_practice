#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int node_count = 6;
int INF = 1000000000;
int dist[7];
vector<pair<int, int>> graph[7];


//dijkstra
void dijkstra(int start)
{
    dist[start] = 0;
    priority_queue<pair<int,int>> pq; //max heap structure
    pq.push({start, 0});
    while(!pq.empty())
    {
        int current = pq.top().first;
        //for reversal effect make it negative
        int dis = -pq.top().second;
        pq.pop();

        if(dist[current] < dis) continue;
        for(int i=0; i<graph[current].size(); ++i)
        {
            int next = graph[current][i].first;
            int cost = dis + graph[current][i].second;
            if(cost < dist[next])
            {
                dist[next] = cost;
                pq.push(make_pair(next, -cost));
            }
        }
    }
}

int main()
{
    for(int i=1; i<=node_count; ++i)
        dist[i] = INF;

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
        cout << dist[i] << " ";
    return 0;
}
