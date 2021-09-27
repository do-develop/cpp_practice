#include <iostream>
//Floyd Warshall Algorithm (dynamic programming)
//O(n^3) --> due to 3 layered for statement

int node_count = 4;
int INF = 1000000000;

//graph distance
int dist[4][4] =
{
    {0, 5, INF, 8},
    {7, 0, 9, INF},
    {2, INF, 0, 4},
    {INF, INF, 3, 0}
};

void floydWarshall()
{
    //initialise result graph
    int result[node_count][node_count];
    for(int i=0; i<node_count; ++i)
    {
        for(int j=0; j<node_count; ++j)
            result[i][j] = dist[i][j];
    }

    //mid --> a node that is being routed
    for(int mid=0; mid<node_count; mid++)
    {
        //start --> start node
        for(int start = 0; start<node_count; start++)
        {
            //dest --> destination node
            for(int dest=0; dest<node_count; dest++)
            {
                if(result[start][mid] + result[mid][dest] < result[start][dest])
                {
                    result[start][dest] = result[start][mid] + result[mid][dest];
                }
            }
        }
    }
    //print the result
    for(int i=0; i<node_count; ++i)
    {
        for(int j=0; j<node_count; ++j)
            std::cout << result[i][j] << ' ';
        std::cout << '\n';
    }

}

int main()
{
    floydWarshall();
    return 0;
}
