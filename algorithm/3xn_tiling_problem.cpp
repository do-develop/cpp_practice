#include <iostream>

/*
int tile[1000]={0}; //for memoization

//Fill out 3xn sized wall with 2x1 and 1x2 sized tiles
// solution pattern:
// tile[n] = 3*tile[n-2] + (2*tile[n-4] + 2*tile[n-6] ... + 2*tile[0])
int tiling_solution(int width)
{
    if(width == 0) return 1;
    if(width == 1) return 0;
    if(width == 2) return 3;
    if(tile[width] != 0) return tile[width];
    int result = 3 * (tiling_solution(width-2));
    for(int i=3; i<=width; i++)
    {
        if(i%2 == 0)
            result += 2 * (tiling_solution(width - i));
    }
    return tile[width] = result;
}

int main()
{
    int cnt;
    std::cout << "How many tile do you want to add? ";
    std::cin >> cnt;

    std::cout << "The count of ways to fill out 3xn size rectangles with 2x1 and 1x2: " << tiling_solution(cnt);

    return 0;
}

*/


//Fill out 2xn sized wall with 2x1, 1x2, and 1x1 sized tiles
// solution pattern:
// tile[n] = 3*tile[n-2] + 2*tile[n-1] + (2*tile[n-3] + 2*tile[n-4]... 2*tile[0])
long long int tile[1000000][2]={0}; //for memoization, 2-dimensional dynamic programming

long long int tiling_solution(int width)
{
    tile[0][0] = 1;
    tile[1][0] = 2;
    tile[2][0] = 7;
    tile[2][1] = 0;

    for(int i=3; i<=width; ++i)
    {
        tile[i][1] = (tile[i-1][1] + tile[i-3][0]) % 1000000007;
        tile[i][0] = (3 * tile[i-2][0] + 2 * tile[i-1][0] + 2 * tile[i][1]) % 1000000007;
    }


    return tile[width][0];
}

int main()
{
    int cnt;
    std::cout << "How much size do you want to increase? ";
    std::cin >> cnt;

    std::cout << "The count of ways to fill out 2xn size rectangles with 2x1, 1x2, and 1x1: " << tiling_solution(cnt);

    return 0;
}

