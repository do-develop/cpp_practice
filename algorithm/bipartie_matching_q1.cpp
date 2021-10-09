//beakjoon 2188
#include <iostream>
#include <vector>
#define MAX 201

using namespace std;

vector<int> graph[MAX]; //start node + edges
int dest[MAX]; //destination node number
bool isMatched[MAX];
int node_count, dest_count, want_count;

bool dfs(int try_node)
{
    for(int i=0; i<graph[try_node].size(); ++i)
    {
        int want_node = graph[try_node][i];
        if(isMatched[want_node]) continue;
        isMatched[want_node] = true;

        if(dest[want_node]==0 || dfs(dest[want_node]))
        {
            dest[want_node] = try_node;
            return true;
        }
    }
    return false;
}

int main(void)
{
    scanf("%d %d", &node_count, &dest_count);
    for(int i=1; i<=node_count; ++i)
    {
        scanf("%d", &want_count);
        for(int j=1; j<=want_count; ++j)
        {
            int wanted_dest;
            scanf("%d", &wanted_dest);
            graph[i].push_back(wanted_dest);
        }
    }
    int cnt = 0;
    for(int i = 1; i <= node_count; ++i)
    {
        fill(isMatched, isMatched + MAX, false);
        if(dfs(i)) cnt++; //once bipartie match was done increase by one
    }
    //print max match count
    printf("%d\n", cnt);

    return 0;
}
