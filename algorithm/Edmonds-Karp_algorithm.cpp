#include <iostream>
#include <vector>
#include <queue>

#define MAX 100
#define INF 1000000000

using namespace std;

int node_count = 6, result; //max flow
int capacity[MAX][MAX], flow[MAX][MAX], path[MAX];
vector<int> graph[MAX];

void maxFlow(int start, int last)
{
    while(1)
    {
        fill(path, path + MAX, -1);
        queue<int> q;
        q.push(start);

        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            for(int i=0; i<graph[x].size(); ++i)
            {
                int near = graph[x][i];
                if(capacity[x][near] - flow[x][near] > 0 && path[near]==-1)
                {
                    q.push(near);
                    path[near] = x; //remember the path
                    if(near == last) break;
                }
            }
        }
        if(path[last]==-1) break;
        int max_flow = INF;
        for(int i=last; i!=start; i=path[i])
        {
            max_flow = min(max_flow, capacity[path[i]][i] - flow[path[i]][i]);
        }

        for(int i=last; i!=start; i=path[i])
        {
           flow[path[i]][i] += max_flow;
           flow[i][path[i]] -= max_flow;
        }
        result += max_flow;
    }
}

int main(void)
{
    graph[1].push_back(2);
    graph[2].push_back(1);
    capacity[1][2] = 12;

    graph[1].push_back(4);
    graph[4].push_back(1);
    capacity[1][4] = 11;

    graph[2].push_back(3);
    graph[3].push_back(2);
    capacity[2][3] = 6;

    graph[2].push_back(4);
    graph[4].push_back(2);
    capacity[2][4] = 3;

    graph[2].push_back(5);
    graph[5].push_back(2);
    capacity[2][5] = 5;

    graph[2].push_back(6);
    graph[6].push_back(2);
    capacity[2][6] = 9;

    graph[3].push_back(6);
    graph[6].push_back(3);
    capacity[3][6] = 8;

    graph[4].push_back(5);
    graph[5].push_back(4);
    capacity[4][5] = 9;

    graph[5].push_back(3);
    graph[3].push_back(5);
    capacity[5][3] = 3;

    graph[5].push_back(6);
    graph[6].push_back(5);
    capacity[5][6] = 4;

    maxFlow(1,6);
    cout << result;
    return 0;
}
