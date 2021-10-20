#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int cnt = 7;
bool visited[7];
vector<int> node_arr[8]; //starting from 1 to 7

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty())
    {
        int near = q.front();
        q.pop();
        printf("%d ", near);
        for(int i=0; i<node_arr[near].size(); i++)
        {
            int connected = node_arr[near][i];
            if(!visited[connected])
            {
                q.push(connected);
                visited[connected] = true;
            }
        }
    }
}

int main(void)
{
    node_arr[1].push_back(2);
    node_arr[1].push_back(3);
    node_arr[2].push_back(1);
    node_arr[2].push_back(3);
    node_arr[2].push_back(4);
    node_arr[2].push_back(5);
    node_arr[3].push_back(1);
    node_arr[3].push_back(2);
    node_arr[3].push_back(6);
    node_arr[3].push_back(7);
    node_arr[4].push_back(2);
    node_arr[4].push_back(5);
    node_arr[5].push_back(2);
    node_arr[5].push_back(4);
    node_arr[6].push_back(3);
    node_arr[6].push_back(7);
    node_arr[7].push_back(3);
    node_arr[7].push_back(6);

    bfs(1);

    return 0;
}
