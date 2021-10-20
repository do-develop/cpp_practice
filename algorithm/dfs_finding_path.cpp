#include <iostream>
#include <vector>

using namespace std;

int cnt = 7;
bool visited[7];
vector<int> node_arr[8];

void dfs(int node_num)
{
    if(visited[node_num]) return;
    visited[node_num] = true;
    cout << node_num << ' ';
    for(int i=0; i<node_arr[node_num].size(); ++i)
    {
        int connected = node_arr[node_num][i];
        dfs(connected);
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

    dfs(1);

    return 0;
}
