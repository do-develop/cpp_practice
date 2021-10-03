//baekjoon Q1516
#include <iostream>
#include <vector>
#include <queue>
#define MAX 501

using namespace std;

int node_count, inDegree[MAX], time[MAX], result[MAX];
vector<int> graph[MAX];

void topologySort()
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

    //visit all nodes
    for(int i=1; i<=node_count; ++i)
    {
        int node = q.front();
        q.pop();
        for(int j=0; j<graph[node].size(); ++j)
        {
            int visit_node = graph[node][j];
            result[visit_node] = max(result[visit_node], result[node] + time[visit_node]);
            if(--inDegree[visit_node] == 0)
                q.push(visit_node);
        }
    }
    //print result
    for(int i=1; i<=node_count; ++i)
        cout << result[i] << ' ';

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
    topologySort();
}
