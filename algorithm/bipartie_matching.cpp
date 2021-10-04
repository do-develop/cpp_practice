//Find max matching using DFS
//O(V * E) //N^2
#include <iostream>
#include <vector>
#define MAX 101

using namespace std;

vector<int> graph[MAX]; //start node + edges
int dest[MAX]; //destination node number
bool isMatched[MAX];
int node_count = 3, edge_count;

//if successfuly matched true, or false
bool dfs(int try_node)
{
    //check all connected nodes for matching
    for(int i=0; i<graph[try_node].size(); ++i)
    {
        int connect = graph[try_node][i];
        //no need to check already processed nodes
        if(isMatched[connect]) continue;
        isMatched[connect] = true;
        //if empty or there is a space to add
        if(dest[connect]==0 || dfs(dest[connect]))
        {
            dest[connect] = try_node;
            return true;
        }
    }
    return false;
}

int main(void)
{
    graph[1].push_back(1);
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(1);
    graph[3].push_back(2);

    int cnt = 0;
    for(int i=1; i<=node_count; ++i)
    {
        fill(isMatched, isMatched+MAX, false);
        if(dfs(i)) cnt++;
    }
    printf("Matched amount: %d\n", cnt);

    for(int i=1; i<=cnt; ++i)
    {
        if(dest[i]!=0)
        {
            printf("%d -> %d\n", dest[i], i);
        }
    }

    return 0;
}
