#include <iostream>
#include <vector>
#include <stack>
#define MAX 10001
//Tarjan's Algorithm
using namespace std;

int id, ids[MAX];
bool finished[MAX];
vector<int> graph[MAX];
vector<vector<int>> SCC;
stack<int> stk;

int dfs(int x)
{
    ids[x] = ++id; //allocate id to each node
    stk.push(x); //push itself to the stack

    int parent = ids[x];
    for(int i=0; i<graph[x].size(); ++i)
    {
        int near = graph[x][i];
        if(ids[near]==0) parent = min(parent,dfs(near));
        else if(!finished[near]) parent = min(parent, ids[near]);
    }

    if(parent==ids[x])
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
        SCC.push_back(scc);
    }
    return parent;
}

int main(void)
{
    int nodes = 11;
    graph[1].push_back(2);
    graph[2].push_back(3);
    graph[3].push_back(1);
    graph[4].push_back(2);
    graph[4].push_back(5);
    graph[5].push_back(7);
    graph[6].push_back(5);
    graph[7].push_back(6);
    graph[8].push_back(5);
    graph[8].push_back(9);
    graph[9].push_back(10);
    graph[10].push_back(11);
    graph[11].push_back(3);
    graph[11].push_back(8);

    for(int i=1; i<=nodes; ++i)
    {
        if(ids[i]==0) dfs(i);
    }

    printf("SCC count: %d\n", SCC.size());
    for(int i=0; i<SCC.size(); ++i)
    {
        printf("SCC %d: ", i+1);
        for(int j=0; j<SCC[i].size(); ++j)
            printf("%d ", SCC[i][j]);
        printf("\n");
    }

    return 0;
}
