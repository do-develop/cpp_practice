#include <string>
#include <iostream>

using namespace std;

bool isOneAway(string str1, string str2)
{
    string short_str, long_str;

    if(str1.length() < str2.length())
    {
        short_str = str1;
        long_str = str2;
    }
    else
    {
        short_str = str2;
        long_str = str1;
    }

    //before checking the length
    if(long_str.length() - short_str.length() > 1) return false;
    bool flag = false;

    for(int i=0, j=0; i < short_str.length(); i++, j++)
    {
        if(short_str[i] != long_str[j])
        {
            if(flag) //means that there has been identification of more than one difference
                return false;
            else
                flag = true;

            if(short_str.length() != long_str.length())
            {
                j++;
            }
        }
    }
    return true;
}

int main()
{
    cout << isOneAway("pal", "pale") << endl;
    cout << isOneAway("pale", "pal") << endl;
    cout << isOneAway("pale", "bale") << endl;

    cout << isOneAway("pal", "pales") << endl;
    cout << isOneAway("pale", "pel") << endl;
    cout << isOneAway("pale", "bake") << endl;
}
