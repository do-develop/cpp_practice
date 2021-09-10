//Check if two strings are permutation of each other

#include <string>
#include <iostream>
#include <algorithm> //sort()
#define NO_OF_CHARS 128

using namespace std;

//method1 O(n^2)/ O(nLogn)
bool arePermutation1(string str1, string str2)
{
    int num1 = str1.length();
    int num2 = str2.length();

    if(num1 != num2)
        return false;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    for(int i=0; i< num1; ++i)
        if(str1[i] != str2[i])
            return false;

    return true;
}

//method2 - more optimised version O(n)
bool arePermutation2(string str1, string str2)
{
    if(str1.length() != str2.length()) return false;
    //initialise
    int letters[NO_OF_CHARS] = {0};
letters[str2[i])
    for(int i=0; i<str1.length(); i++)
    {
        letters[str1[i]]++;
    }
    for(int i=0; i<str2.length(); i++)
    {
        letters[str2[i]]--;
        if(letters[str2[i]] < 0) return false;
    }
    return true;
}

int main()
{
    string str1 = "peace";
    string str2 = "piece";
    string str3 = "cepea";

    if(arePermutation2(str1, str2))
        cout << "Yes\n";
    else
        cout << "No\n";

    if(arePermutation2(str1, str3))
        cout << "Yes\n";
    else
        cout << "No\n";
}
