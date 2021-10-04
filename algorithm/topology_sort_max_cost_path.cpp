//Baekjoon 1948

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

int start, finish;
int inDegree[MAX], result[MAX], checked[MAX];
vector<Edge> sf[MAX]; //start to finish
vector<Edge> fs[MAX]; //finsh to start

void topologySort()
{
    queue<int> q;
    //insert start node to queue
    q.push(start);
    //until there is no node to visit
    while(!q.empty())
    {
        int frnt = q.front();
        q.pop();
        for(int i=0; i<sf[frnt].size(); ++i)
        {
            //adjacent edge
            Edge adj = Edge(sf[frnt][i].node, sf[frnt][i].time);
            if(result[adj.node] <= adj.time + result[frnt])
            {
                result[adj.node] = adj.time + result[frnt];
            }

            if(--inDegree[adj.node] == 0)
            {
                q.push(adj.node);
            }
        }
    }
    //reverse track on result
    int cnt = 0; //node count from max cost path
    q.push(finish);
    while(!q.empty())
    {
        int bck = q.front(); //node from back(finish)
        q.pop();
        for(int i=0; i<fs[bck].size(); ++i)
        {
            Edge adj = Edge(fs[bck][i].node, fs[bck][i].time);
            //check if max cost path
            if(result[bck] - result[adj.node] == adj.time)
            {
                cnt++;
                if(checked[adj.node]==0)
                {
                    q.push(adj.node);
                    checked[adj.node] = 1;
                }
            }
        }
    }
    printf("%d\n%d", result[finish], cnt);
}

int main(void)
{
    int node_count,path_count;
    scanf("%d %d", &node_count, &path_count);
    for(int i=0; i<path_count; ++i)
    {
        int first, next, time;
        scanf("%d %d %d", &first, &next, &time);
        sf[first].push_back(Edge(next, time));
        fs[next].push_back(Edge(first, time));
        inDegree[next]++;
    }
    scanf("%d %d", &start, &finish);
    topologySort();
}
