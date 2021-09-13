#include <string>
#include <iostream>
#include <map>
using namespace std;


//follow assumes that string is only ASCII
/*
bool isUnique(string str)
{
    if(str.length() > 128) return false;
    bool char_set[128] = {false};
    for(int i=0; i<str.length(); ++i)
    {
        int val = str.at(i);
        if(char_set[val])
        {
            return false;
        }
        char_set[val] = true;
    }
    return true;
}
*/


//map version
/*
bool isUnique(string str)
{
    map<int, bool> strmap;

    for(int i = 0; i < str.length(); ++i)
    {
        int c = str.at(i);
        if(strmap.find(c)!=strmap.end())
            return false;
        strmap.insert(pair<int, bool>(c, true));
    }
    return true;
}
*/

//bit operator version
bool isUnique(string str)
{
    int checker = 0;
    for(int i=0; i<str.length(); ++i)
    {
        int val = str.at(i) - 'a'; // -97
        if((checker & (1 << val)) > 0)
            return false;
        checker |= (1 << val);
    }
    return true;
}

int main()
{
    cout << isUnique("abcdefgghijk") << endl;
    cout << isUnique("abcdefghijklmn") << endl;
}
