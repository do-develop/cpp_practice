//dynamic algorithm
//fibonacci with memoization O(N)
#include <iostream>

int memo[100] = {0};

int fibo(int x)
{
    if(x == 1) return 1;
    if(x == 2) return 1;
    if(memo[x] != 0) return memo[x];
    return memo[x] = fibo(x-1) + fibo(x-2);
}

int main(void)
{
    std::cout << fibo(30) << "\n";
    return 0;
}
