#include <iostream>
#include <vector>

using namespace std;

int node_count = 7;
int visited[7];
vector<int> graph[8];

void dfs(int location)
{
    if(visited[location]) return;
    visited[location] = true;
    cout << location << ' ';

    for(int i=0; i<graph[location].size(); ++i)
    {
        int connected_node = graph[location][i];
        dfs(connected_node);
    }
}

int main(void)
{
    //making a graph
    graph[1].push_back(2);
    graph[1].push_back(3);

    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[2].push_back(4);
    graph[2].push_back(5);

    graph[3].push_back(1);
    graph[3].push_back(2);
    graph[3].push_back(6);
    graph[3].push_back(7);

    graph[4].push_back(2);
    graph[4].push_back(5);

    graph[5].push_back(2);
    graph[5].push_back(4);

    graph[6].push_back(3);
    graph[6].push_back(7);

    graph[7].push_back(3);
    graph[7].push_back(6);

    dfs(1);

    return 0;
}
