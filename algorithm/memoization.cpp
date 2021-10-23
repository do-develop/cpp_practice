#include <iostream>

int fibo[100];

//if only using recursive method, the calculation takes long time
int fibonacci(int x)
{
    if(x==1) return 1;
    if(x==2) return 1;
    if(fibo[x]!=0) return fibo[x]; //memoization
    return fibo[x] = fibonacci(x-1) + fibonacci(x-2);
}

int main(void)
{
    printf("%d", fibonacci(30));
    return 0;
}
