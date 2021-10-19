// baekjoon 10989
#include <iostream>

using namespace std;

int cnt;
int numbers[10001];

int main(void)
{
    scanf("%d", &cnt);

    for(int i=0; i<cnt; ++i)
    {
        int input;
        scanf("%d", &input);
        numbers[input]++;
    }

    for(int i=0; i<10001; ++i)
    {
        while(numbers[i]!=0)
        {
            printf("%d\n", i);
            numbers[i]--;
        }
    }

    return 0;
}
