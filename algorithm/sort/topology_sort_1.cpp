//can be apply only to DAG
//Directed Acyclic Graph
//Requires starting point
//Uses queue

#include <iostream>
#include <queue>

#define MAX 10

using namespace std;

int node_count, inDegree[MAX];
vector<int> graph[MAX];

void topologySort()
{
    int result[MAX];
    queue<int> q;

    for(int i=1; i<=node_count; ++i)
    {
        if(inDegree[i]==0) q.push(i);
    }
    //visit node_count amount
    for(int i=1; i<=node_count; ++i)
    {
        if(q.empty()) //if the queue empties before the complete visit
        {
            printf("Cycle detected!");
            return;
        }
        int visit = q.front();
        q.pop();
        result[i] = visit;
        for(int i=0; i<graph[visit].size(); ++i)
        {
            int connected = graph[visit][i];
            if(--inDegree[connected]==0)
            {
                q.push(connected);
            }
        }
    }

    //print the result
    for(int i=1; i<=node_count; ++i)
        printf("%d ", result[i]);
}

int main(void)
{
    node_count = 7;
    graph[1].push_back(2);
    inDegree[2]++;
    graph[1].push_back(5);
    inDegree[5]++;
    graph[2].push_back(3);
    inDegree[3]++;
    graph[3].push_back(4);
    inDegree[4]++;
    graph[4].push_back(6);
    inDegree[6]++;
    graph[5].push_back(6);
    inDegree[6]++;
    graph[6].push_back(7);
    inDegree[7]++;

    topologySort();

    return 0;
}
