//Find matching string pattern
//O(N * M)
#include <iostream>

using namespace std;

int findString(string parent, string pattern)
{
    int parentSize = parent.size();
    int patternSize = pattern.size();

    for(int i=0; i<=parentSize-patternSize; ++i)
    {
        bool found = true;
        for(int j=0; j < patternSize; ++j)
        {
            if(parent[i+j] != pattern[j])
            {
                found = false;
                break;
            }
        }
        if(found)
        {
            return i;
        }
    }
    return -1;
}

int main(void)
{
    string parent = "Hello World";
    string pattern = "o W";
    int result = findString(parent, pattern);
    if(result == -1)
    {
        printf("Can't find pattern");
    }
    else
    {
        printf("Found at %d", result+1);
    }

    return 0;
}
