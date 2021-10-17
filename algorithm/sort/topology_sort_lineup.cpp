#include <iostream>
#include <vector>
#include <queue>
#define MAX 32001

using namespace std;

int node_count, inDegree[MAX], result[MAX];
vector<int> graph[MAX];

void topologySort()
{
    queue<int> q;

    for(int i=1; i<=node_count; ++i)
    {
        if(inDegree[i]==0)
        {
            q.push(i);
        }
    }

    //visit all nodes
    for(int i=1; i<=node_count; ++i)
    {
        int node = q.front();
        q.pop();
        result[i] = node;
        for(int j=0; j<graph[node].size(); ++j)
        {
            int visit_node = graph[node][j];
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
    int vertex_count;
    scanf("%d %d", &node_count, &vertex_count);
    for(int i=0; i<vertex_count; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x].push_back(y);
        inDegree[y]++;
    }
    topologySort();
}
