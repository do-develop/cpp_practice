//This algorithm can be performed only on DAG(Directed Acyclic Graph)
//Using queue
// O(V + E) //(vertex + edges)
#include <iostream>
#include <vector>
#include <queue>
#define MAX 10

using namespace std;

int node_count, inDegree[MAX]={0};
vector<int> arr[MAX];

void topologySort()
{
    int result[MAX];
    queue<int> q;

    //if indegree is 0, insert the node in the queue
    for(int i=1; i<=node_count; ++i)
    {
        if(inDegree[i] == 0) q.push(i);
    }

    //to complete topology sort, node should be visited for node_count amount
    for(int i=1; i<=node_count; ++i)
    {
        //if queue is empty before visiting node_count amount --> cycle happend
        if(q.empty())
        {
            cout << "The graph is not acyclic!\n";
            return;
        }
        int node = q.front();
        q.pop();
        result[i] = node;
        for(int i=0; i<arr[node].size(); i++)
        {
            int connected = arr[node][i];
            if(--inDegree[connected] == 0 )
                q.push(connected);
        }
    }
    for(int i=1; i<=node_count; ++i)
        cout << result[i] << ' ';
}

int main(void)
{
    node_count = 7;

    arr[1].push_back(2);
    inDegree[2]++;
    arr[1].push_back(5);
    inDegree[5]++;
    arr[2].push_back(3);
    inDegree[3]++;
    arr[3].push_back(4);
    inDegree[4]++;
    arr[4].push_back(6);
    inDegree[6]++;
    arr[5].push_back(6);
    inDegree[6]++;
    arr[6].push_back(7);
    inDegree[7]++;

    topologySort();

    return 0;
}
