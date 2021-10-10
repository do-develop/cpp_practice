// Baekjoon 2150 SCC
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 10001

using namespace std;

int id, ids[MAX];
bool finished[MAX];// if DFS is done
vector<int> graph[MAX];
vector<vector<int>> SCC;
stack<int> result;

int dfs(int node)
{
    ids[node] = ++id; //assign id to each node
    result.push(node);

    int parent = ids[node];
    for(int i=0; i<graph[node].size(); ++i)
    {
        int near = graph[node][i];
        //unvisited neighbor's parent will be changed to the minimal value
        if(ids[near] == 0) parent = min(parent, dfs(near));
        //visited but processing neighbor
        else if(!finished[near]) parent = min(parent, ids[near]);
    }

    if(parent == ids[node])
    {
        vector<int> scc;
        while(1)
        {
            int result_item = result.top();
            result.pop();
            scc.push_back(result_item);
            finished[result_item] = true;
            if(result_item == node) break;
        }
        sort(scc.begin(), scc.end());
        SCC.push_back(scc);
    }
    return parent;
}

int main()
{
    int v, e;
    scanf("%d %d", &v, &e);
    for(int i=0; i<e; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x].push_back(y);
    }
    for(int i=1; i<=v; ++i)
    {
        if(ids[i] == 0) dfs(i);
    }
    printf("%d\n", SCC.size());
    sort(SCC.begin(), SCC.end());
    for(int i=0; i<SCC.size(); ++i)
    {
        for(int j=0; j<SCC[i].size(); ++j)
        {
            printf("%d ", SCC[i][j]);
        }
        printf("-1\n");
    }
    return 0;
}
