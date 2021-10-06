//KMP algorithm
//Knuth-Morris-Pratt

#include <iostream>
#include <vector>

using namespace std;

vector<int> makeTable(string pattern)
{
    int patternSize = pattern.size();
    vector<int> table(patternSize, 0); //initialise vector
    int j=0;
    for(int i=1; i<patternSize; i++)
    {
        while(j > 0 && pattern[i] != pattern[j])
        {
            j = table[j - 1];
        }
        if(pattern[i] == pattern[j])
        {
            table[i] = ++j;
        }
    }
    return table;
}

void KMP(string parent, string pattern)
{
    vector<int> table = makeTable(pattern);
    int parentSize = parent.size();
    int patternSize = pattern.size();

    int j = 0;
    for(int i=0; i<parentSize; ++i)
    {
       while(j > 0 && parent[i] != pattern[j])
       {
           j = table[j - 1];
       }
       if(parent[i] == pattern[j])
       {
           if(j == patternSize-1)//all matched!
           {
               printf("Found the pattern from parent location: %d\n", i - patternSize + 2);
               j = table[j]; //
           }
           else
           {
               j++;
           }
       }
    }
}

int main(void)
{
    string parent = "ababacabacaabacaaba";
    string pattern = "abacaaba";
    KMP(parent, pattern);
    return 0;
}
