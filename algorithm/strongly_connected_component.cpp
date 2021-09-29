//SCC Algorithm (Strongly Connected Component)
//components have cyclic property
//--> Tarjan's Algorithm to find SCC using DFS
// O(V + E)

#include <iostream>
#include <vector>
#include <stack>
#define MAX 10001

using namespace std;

int id=0, ids[MAX];
bool finished[MAX];// if DFS is done
vector<int> graph[MAX];
vector<vector<int>> SCC;
stack<int> result;

//perfrom DFS for the amount of node counts
int dfs(int node)
{
    ids[node] = ++id; //assign id to each node
    result.push(node); //insert self into the result stack

    int parent = ids[node];
    //check adjecent nodes
    for(int i=0; i<graph[node].size(); ++i)
    {
        int near = graph[node][i];
        //unvisited neighbor's parent will be changed to the minimal value
        if(ids[near] == 0) parent = min(parent, dfs(near));
        //processing neighbor
        else if(!finished[near]) parent = min(parent, ids[near]);
    }
    if(parent == ids[node])
    {
        vector<int> scc;
        while(1)
        {
            int temp = result.top();
            result.pop();
            scc.push_back(temp);
            finished[temp] = true;
            //finish while loop once the self is popped
            if(temp == node) break;
        }
        SCC.push_back(scc);
    }

    return parent;
}

int main(void)
{
    int vertex_count = 11;

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

    for(int i=1; i<=vertex_count; ++i)
    {
        if(ids[i] == 0) dfs(i);
    }

    cout << "The number of SCC: " << SCC.size() << "\n";
    for(int i=0; i<SCC.size(); ++i)
    {
        cout << "SCC " << i+1 << ": ";
        for(int j=0; j<SCC[i].size(); ++j)
        {
            cout << SCC[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
