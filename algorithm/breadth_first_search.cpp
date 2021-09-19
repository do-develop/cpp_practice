//BFS using queue
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int node_count = 7;
bool visited[7];
vector<int> graph[8];//just to start from 1 and count to 7

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        printf("%d ", x);
        for(int i=0; i<graph[x].size(); ++i)
        {
            int connected_node = graph[x][i];
            if(!visited[connected_node])
            {
                q.push(connected_node);
                visited[connected_node] = true;
            }
        }
    }
}

int main(void)
{
    //making a graph
    graph[1].push_back(2);
    graph[1].push_back(3);

    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[2].push_back(4);
    graph[2].push_back(5);

    graph[3].push_back(1);
    graph[3].push_back(2);
    graph[3].push_back(6);
    graph[3].push_back(7);

    graph[4].push_back(2);
    graph[4].push_back(5);

    graph[5].push_back(2);
    graph[5].push_back(4);

    graph[6].push_back(3);
    graph[6].push_back(7);

    graph[7].push_back(3);
    graph[7].push_back(6);

    bfs(1);

    return 0;
}
