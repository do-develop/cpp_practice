//Beakjoon 1181
//Print the shorter
//if same length, then dictionary order

#include <iostream>
#include <algorithm>

using namespace std;

string arr[20000];
int n;

bool compare(string a, string b)
{
    if(a.length() < b.length())
    {
        return true;
    }
    else if (a.length() > b.length())
    {
        return false;
    }
    else
    {
        return a < b; //cpp string can compare in dictionary order
    }
}

int main(void)
{
    cin >> n;
    for(int i=0; i < n; ++i)
    {
        cin >> arr[i];
    }
    sort(arr, arr+n, compare);
    for(int i=0; i<n; i++)
    {
        if(i > 0 && arr[i] == arr[i-1])
            continue;
        else
            cout << arr[i] << '\n';
    }
}
