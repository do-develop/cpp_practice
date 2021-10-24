#include <iostream>

/*
int solutions[1001];

int getSolution(int x)
{
    if(x==1) return 1;
    if(x==2) return 2;
    if(solutions[x]!=0) return solutions[x];
    return solutions[x] = (getSolution(x-1) + getSolution(x-2)) %10007; //%10007 to prevent overflow
}

int getSolution(int x)
{
    if(x==1) return 1;
    if(x==2) return 3;
    if(solutions[x]!=0) return solutions[x];
    return solutions[x] = (getSolution(x-1) + 2*getSolution(x-2)) %10007; //%10007 to prevent overflow
}

int getSolution(int x)
{
    if(x==0) return 1;
    if(x==1) return 0;
    if(x==2) return 3;
    if(solutions[x]!=0) return solutions[x];
    int result = 3*getSolution(x-2);
    for(int i=3; i<=x; i++)
    {
        if(i%2 == 0)
            result += 2*(x-i);
    }
    return solutions[x] = result;
}
*/

//2 dimensional dynamic programming example
long long int d[1000001][2];

long long int dp(int x)
{
    d[0][0] = 1;
    d[1][0] = 2;
    d[2][0] = 7;
    d[2][1] = 0;

    for(int i=3; i<=x; i++)
    {
        d[i][1] = (d[i-1][1] + d[i-3][0]) %1000000007;
        d[i][0] = (3*d[i-2][0] + 2*d[i-1][0]+ 2*d[i][1]) %1000000007;
    }
    return d[x][0];
}

int main(void)
{
    int x;
    scanf("%d", &x);
    printf("%d\n", dp(x));
    return 0;
}
