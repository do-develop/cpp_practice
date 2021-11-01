#include <iostream>

using namespace std;

int find_string(string parent, string pattern)
{
    int parent_size = parent.size();
    int pattern_size = pattern.size();

    for(int i=0; i<=parent_size - pattern_size; ++i)
    {
        bool found = true;
        for(int j=0; j<pattern_size; ++j)
        {
            if(parent[i+j]!=pattern[j])
            {
                found = false;
                break;
            }
        }
        if(found)
            return i;
    }
    return -1;
}

int main(void)
{
    string parent = "This is the new world";
    string pattern = "she";
    int result = find_string(parent, pattern);

    if(result == -1)
    {
        cout << "String pattern not found\n";
    }
    else
    {
        cout << "String pattern found at " << result+1 << '\n';
    }
}
