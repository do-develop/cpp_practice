#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

#define MAX 10001

using namespace std;

int id, parent[MAX];
bool finished[MAX];
vector<int> graph[MAX];
vector<vector<int>> SCC;
stack<int> stk;

int dfs(int x)
{
    parent[x] = ++id;
    stk.push(x);

    int result = parent[x];
    for(int i=0; i<graph[x].size(); ++i)
    {
        int near = graph[x][i];
        if(parent[near] == 0) result = min(result, dfs(near));
        else if(!finished[near]) result = min(result, parent[near]);
    }

    if(result == parent[x])
    {
        vector<int> scc;
        while(1)
        {
            int temp = stk.top();
            stk.pop();
            scc.push_back(temp);
            finished[temp] = true;
            if(temp == x) break;
        }
        sort(scc.begin(), scc.end());
        SCC.push_back(scc);
    }
    return result;
}

int main()
{
    int node_count, line_count;
    scanf("%d %d", &node_count, &line_count);
    for(int i=0; i<line_count; ++i)
    {
        int start, dest;
        scanf("%d %d", &start, &dest);
        graph[start].push_back(dest);
    }

    for(int i=1; i<node_count; ++i)
    {
        if(parent[i]==0) dfs(i);
    }

    printf("%d\n", SCC.size());
    sort(SCC.begin(), SCC.end());
    for(int i=0; i<SCC.size(); ++i)
    {
        for(int j=0; j<SCC[i].size(); ++j)
            printf("%d ", SCC[i][j]);
        cout << '\n';
    }
    return 0;
}
