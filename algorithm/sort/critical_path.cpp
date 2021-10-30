#include <iostream>
#include <vector>
#include <queue>

//Baekjoon 2252
/*
#define MAX 32000

using namespace std;

int node_count, inDegree[MAX], result[MAX];
vector<int> graph[MAX];

void topology_sort()
{
    queue<int> q;
    for(int i=1; i<=node_count; ++i)
    {
        if(inDegree[i]==0)
        {
            q.push(i);
        }
    }
    for(int i=1; i<=node_count; ++i)
    {
        int x = q.front();
        q.pop();
        result[i] = x;
        for(int j=0; j<graph[x].size(); ++j)
        {
            int near = graph[x][j];
            if(--inDegree[near]==0) q.push(near);
        }
    }
    for(int i=1; i<=node_count; ++i)
    {
        printf("%d ", result[i]);
    }
}

int main(void)
{
    int line_count;
    scanf("%d %d", &node_count, &line_count);
    for(int i=0; i<line_count; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x].push_back(y);
        inDegree[y]++;
    }
    topology_sort();

    return 0;
}
*/

/*
#define MAX 501
using namespace std;

int node_count, inDegree[MAX], time[MAX], result[MAX];
vector<int> graph[MAX];

void topology_sort()
{
    queue<int> q;
    for(int i=1; i<=node_count; ++i)
    {
        if(inDegree[i]==0)
        {
            result[i] = time[i];
            q.push(i);
        }
    }
    for(int i=1; i<=node_count; ++i)
    {
        int x = q.front();
        q.pop();
        for(int j=0; j<graph[x].size(); ++j)
        {
            int near = graph[x][j];
            result[near] = max(result[near], result[x] + time[near]);
            if(--inDegree[near]==0)
                q.push(near);
        }
    }
    for(int i=1; i<=node_count; ++i)
    {
        printf("%d ", result[i]);
    }
}

int main(void)
{
    scanf("%d", &node_count);
    for(int i=1; i<=node_count; ++i)
    {
        scanf("%d", &time[i]);
        while(1)
        {
            int cost;
            scanf("%d", &cost);
            if(cost == -1) break;
            inDegree[i]++;
            graph[cost].push_back(i);
        }
    }
    topology_sort();

    return 0;
}
*/

//Baekjoon 1948
//Get all critical path!

#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001

using namespace std;

class Edge{
public:
    int node;
    int time;
    Edge(int node, int time)
    {
        this->node = node;
        this->time = time;
    }
};

int node_count, start, finish;
int inDegree[MAX], result[MAX], processed[MAX];
vector<Edge> track[MAX];
vector<Edge> back_track[MAX];

void topology_sort()
{
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(int i=0; i<track[x].size(); ++i)
        {
            Edge near = Edge(track[x][i].node, track[x][i].time);
            if(result[near.node] <= near.time + result[x])
            {
                result[near.node] = near.time + result[x];
            }
            if(--inDegree[near.node] == 0)
            {
                q.push(near.node);
            }
        }
    }
    //back track the result
    int cnt = 0;
    q.push(finish);
    while(!q.empty())
    {
        int y = q.front();
        q.pop();
        for(int i=0; i<back_track[y].size(); ++i)
        {
            Edge near = Edge(back_track[y][i].node, back_track[y][i].time);
           //check if it is the critical path
           if(result[y] - result[near.node] == near.time)
           {
               cnt++;
               if(processed[near.node]==0)
               {
                   q.push(near.node);
                   processed[near.node] = 1;
               }
           }
        }
    }
    printf("%d\n%d", result[finish], cnt);
}

int main(void)
{
    int line_count;
    scanf("%d %d", &node_count, &line_count);
    for(int i=0; i<line_count; ++i)
    {
        int from, to, time;
        scanf("%d %d %d", &from, &to, &time);
        track[from].push_back(Edge(to, time));
        back_track[to].push_back(Edge(from, time));
        inDegree[to]++;
    }
    scanf("%d %d", &start, &finish);
    topology_sort();

    return 0;
}
