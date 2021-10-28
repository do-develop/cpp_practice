#include <iostream>

int node_count = 4;
int INF = 10000000;

int graph[4][4] =
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
            result[i][j] = graph[i][j];
    }

    for(int visiting=0; visiting < node_count; ++visiting)
    {
        for(int start=0; start<node_count; ++start)
        {
            for(int dest=0; dest<node_count; ++dest)
            {
                if(result[start][visiting] + result[visiting][dest] < result[start][dest])
                    result[start][dest] = result[start][visiting] + result[visiting][dest];
            }
        }
    }

    //print the result
    for(int i=0; i<node_count; ++i)
    {
        for(int j=0; j<node_count; ++j)
            printf("%d ", result[i][j]);
        std::cout<<"\n";
    }
}

int main(void)
{
    floydWarshall();
    return 0;
}
