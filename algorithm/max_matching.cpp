#include <iostream>
#include <vector>
#define MAX 101

using namespace std;

vector<int> graph[MAX];
int dest[MAX]; //destination
bool checked[MAX];

int node_count = 3, line_count;

//DFS
bool isMatched(int node)
{
    for(int i=0; i<graph[node].size(); ++i)
    {
        int connected = graph[node][i];
        if(checked[connected]) continue;
        checked[connected] = true;

        if(dest[connected]==0 || isMatched(dest[connected]))
        {
            dest[connected] = node;
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
        fill(checked, checked + MAX, false);
        if(isMatched(i)) cnt++;
    }

    printf("Matching count: %d\n", cnt);
    for(int i=1; i<MAX; ++i)
    {
        if(dest[i] != 0)
            printf("%d -> %d\n", dest[i], i);
    }

    return 0;
}
