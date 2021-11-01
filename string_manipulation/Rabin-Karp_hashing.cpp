#include <iostream>
//O(N)
using namespace std;

void find_string(string parent, string pattern)
{
    int parent_size = parent.size();
    int pattern_size = pattern.size();
    int parent_hash = 0, pattern_hash = 0, power = 1;
    for(int i=0; i<=parent_size - pattern_size; ++i)
    {
        if(i==0) //initialise hash value
        {
            for(int j=0; j<pattern_size; ++j)
            {
                parent_hash += parent[pattern_size-1-j] * power;
                pattern_hash += pattern[pattern_size-1-j] * power;
                if(j < pattern_size -1) power *= 2;
            }
        }
        else
        {
            parent_hash = 2 * (parent_hash - parent[i-1]*power) + parent[i+pattern_size-1];
        }
        if(parent_hash == pattern_hash)
        {
            //clash check first
            bool found = true;
            for(int j=0; j<pattern_size; ++j)
            {
                if(parent[i + j] != pattern[j])
                {
                    found = false;
                    break;
                }
            }
            if(found)
            {
                printf("Found at %d\n", i+1);
            }
        }
    }
}

int main(void)
{
    string parent = "ababacabacaabacaaba";
    string pattern = "abacaaba";
    find_string(parent, pattern);
}
