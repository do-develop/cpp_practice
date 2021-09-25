//dynamic algorithm

#include <iostream>

//2xn tiling problem
//fill out 2xn rectangle with 2x1 tile
//the pattern of the solution
// --> tile[n] = tile[n-1] + tile[n-2]
int tile[1001]={0}; //to start from 1

//2x1 tile only
int tiling_solution1(int added)
{
    if(added == 1) return 1;
    if(added == 2) return 2;
    if(tile[added] != 0) return tile[added];
    return tile[added] = (tiling_solution1(added-1) + tiling_solution1(added - 2))% 10007; //% 10007 to prevent overflow
}


//2xn tiling problem
// fill out 2xn rectangle with 2x1 tile and 2x2 tile
// the find pattern of the solution
// --> tile[n] = tile[n-1] + 2xtile[n-2]

//2x1 and 2x2 tile
int tiling_solution2(int added)
{
    if(added == 1) return 1;
    if(added == 2) return 3;
    if(tile[added] != 0) return tile[added];
    return tile[added] = (tiling_solution2(added-1) + 2 * tiling_solution2(added - 2))% 10007; //% 10007 to prevent overflow
}

int main(void)
{
    int cnt;
    std::cout << "How many tile do you want to add? ";
    std::cin >> cnt;

    std::cout << "The count of ways to fill out rectangles in 2xn size: " << tiling_solution2(cnt);
	
	return 0;
}
