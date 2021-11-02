#include <iostream>
#include <vector>
#define MAX 201

using namespace std;

vector<int> graph[MAX];
int destination[MAX];
bool checked[MAX];
int cow_count, farm_count, want_count;

bool dfs(int x)
{
    for(int i=0; i<graph[x].size(); ++i)
    {
        int connected_node = graph[x][i];
        //do not process the checked node again
        if(checked[connected_node]) continue;
        checked[connected_node] = true;
        if(destination[connected_node]==0
           || dfs(destination[connected_node]))
        {
            destination[connected_node] = x;
            return true;
        }
    }
    return false;
}

int main(void)
{
    scanf("%d %d", &cow_count, &farm_count);
    for(int i=1; i<=cow_count; ++i)
    {
        scanf("%d", &want_count);
        for(int j=1; j<=want_count; ++j)
        {
            int temp;
            scanf("%d", &temp);
            graph[i].push_back(temp);
        }
    }
    //bipartie matching algorithm
    int match_count = 0;
    for(int i=1; i<=cow_count; i++)
    {
        fill(checked, checked + MAX, false);
        if(dfs(i)) match_count++;
    }
    //print the max match count result
    printf("%d",match_count);

    return 0;
}
