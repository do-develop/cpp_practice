//Rabin-Karp Algorithm
//O(N)
//It uses hash value and pointers

#include <iostream>

using namespace std;

void findString(string parent, string pattern)
{
    int parentSize = parent.size();
    int patternSize = pattern.size();
    int parentHash = 0, patternHash = 0, power = 1;
    for(int i=0; i <= parentSize-patternSize; i++)
    {
        if(i==0) //initialisation
        {
            for(int j=0; j<patternSize; ++j)
            {
                //from right to left
                parentHash += parent[patternSize -1 -j] * power;
                patternHash += pattern[patternSize -1 -j] * power;
                if(j < patternSize-1) power*=2;
            }
        }
        else
        {
            parentHash = 2 * (parentHash - parent[i-1]*power) + parent[patternSize -1 +i];
        }
        if(parentHash == patternHash)
        {
            bool found = true;
            //below is to check collision
            for(int j=0; j<patternSize; ++j)
            {
                if(parent[i+j] != pattern[j])
                {
                    found = false;
                    break;
                }
            }
            if(found)
            {
                printf("Found at location %d\n", i+1);
            }
        }
    }
}

int main(void)
{
    string parent = "ababacabacaabacaaba";
    string pattern = "abacaaba";
    findString(parent, pattern);

    return 0;
}
