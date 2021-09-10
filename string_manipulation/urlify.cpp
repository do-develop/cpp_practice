//string url encoding
#include <string>
#include <iostream>

using namespace std;

string urlify(char str[], int len)
{
    int space_count = 0;
    for(int i=0; i<len; i++)
    {
        if(str[i]==' ')space_count++;
    }

    //new string
    int idx = len + space_count*2 -1;
    for(int ptr=len-1; ptr>=0; ptr--)
    {
        if(str[ptr] == ' ')
        {
            str[idx--] = '0';
            str[idx--] = '2';
            str[idx--] = '%';
        }
        else
        {
            str[idx--] = str[ptr];
        }
    }
    return str;
}

int main()
{
    char str[] = "Mr John Smith     ";
    cout << urlify(str,13);

    return 0;
}
