#include <iostream>
#include <math.h>

//find prime number using square root
bool isPrimeNumber(int x)
{
    int end = (int) sqrt(x);
    for(int i=2; i <= end; ++i)
    {
        if(x % i == 0) return false;
    }
    return true;
}

//seive of Eratosthenes
int number = 100000;
int arr[100001];
void primeNumberSieve()
{
    for(int i=2; i <= number; ++i)
        arr[i] = i;
    for(int i=2; i <= number; ++i)
    {
        if(arr[i] == 0) continue;
        for(int j=i+i; j<=number; j+=i)
            arr[j] = 0;
    }
    for(int i=2; i <= number; ++i)
    {
        if(arr[i] != 0) std::cout << arr[i] <<" ";
    }
}

int main(void)
{
    //std::cout << isPrimeNumber(97);
    primeNumberSieve();
    return 0;
}
