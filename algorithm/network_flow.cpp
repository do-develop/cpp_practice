//max flow algorithm
//Edmonds-Karp Algorithm O(VE^2)
#include <iostream>
#include <vector>
#include <queue>

#define MAX 100 //max node count
#define INF 1000000000

using namespace std;

int node = 6, result;
//cap = capacity
int cap[MAX][MAX], flow[MAX][MAX], visit[MAX];
vector<int> graph[MAX];

void maxFlow(int start, int last)
{
    while(1)
    {
        //initialise visit array with '-1'
        fill(visit, visit + MAX, -1);
        //bfs
        queue<int> q;
        q.push(start);
        while(!q.empty())
        {
            int frnt = q.front();
            q.pop();
            for(int i=0; i<graph[frnt].size(); ++i)
            {
                int connected = graph[frnt][i];
                //among unvisited node, capacity is not full yet
                if(cap[frnt][connected] - flow[frnt][connected]
                   && visit[connected]==-1)
                {
                    q.push(connected);
                    visit[connected] = frnt; // to memorise the path
                    if(connected == last) break; //reached the last node
                }
            }
        }
        //tried every possible path --> the last remains '-1'
        if(visit[last] == -1) break;
        int min_flow = INF;

        //search the min flow in reverse direction
        for(int i=last; i!=start; i = visit[i]) //as visit[] remembers the previously visited node (path)
        {
            min_flow = min(min_flow, cap[visit[i]][i] - flow[visit[i]][i]);
        }
        //add min flow
        for(int i=last; i!=start; i = visit[i]) //as visit[] remembers the previously visited node (path)
        {
            flow[visit[i]][i] += min_flow;
            flow[i][visit[i]] -= min_flow;
        }
        result += min_flow; //max flow
    }
}

int main()
{
    graph[1].push_back(2);
    graph[2].push_back(1);
    cap[1][2] = 12;

    graph[1].push_back(4);
    graph[4].push_back(1);
    cap[1][4] = 11;

    graph[2].push_back(3);
    graph[3].push_back(2);
    cap[2][3] = 6;

    graph[2].push_back(4);
    graph[4].push_back(2);
    cap[2][4] = 3;

    graph[2].push_back(5);
    graph[5].push_back(2);
    cap[2][5] = 5;

    graph[2].push_back(6);
    graph[6].push_back(2);
    cap[2][6] = 9;

    graph[3].push_back(6);
    graph[6].push_back(3);
    cap[3][6] = 8;

    graph[4].push_back(5);
    graph[5].push_back(4);
    cap[4][5] = 9;

    graph[5].push_back(3);
    graph[3].push_back(5);
    cap[5][3] = 3;

    graph[5].push_back(6);
    graph[6].push_back(5);
    cap[5][6] = 4;

    maxFlow(1,6);
    cout << result;
    return 0;
}
