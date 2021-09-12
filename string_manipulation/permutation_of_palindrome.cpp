#include <iostream>
#include <string>

using namespace std;

int getCharNumber(char c)
{
    int a = int('a');
    int z = int('z');
    int val = int(c);

    if(a <= c && c <= z)
        return val - a;

    return -1;
}

bool isPermutationOfPalindrome(string str)
{
    int table_size = int('z') - int('a') + 1;
    int table[table_size] = {0};
    int countOdd = 0;

    for(char c : str)
    {
        int x = getCharNumber(c);
        if(x != -1)
        {
            table[x]++;
            if(table[x] % 2 == 1)
            {
                countOdd++;
            }
            else
            {
                countOdd--;
            }
        }
    }

    return countOdd <= 1;
}

int main()
{
    cout << isPermutationOfPalindrome("aa bb cc dd") << endl;
    cout << isPermutationOfPalindrome("aa bb cc dd e") << endl;
    cout << isPermutationOfPalindrome("aa bb cc dd e fff") << endl;
    return 0;
}
