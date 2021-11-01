#include <iostream>
#include <vector>

using namespace std;

vector<int> make_kmp_table(string pattern)
{
    int pattern_size = pattern.size();
    vector<int> table(pattern_size, 0);
    int j = 0;
    for(int i=1; i<pattern_size; ++i)
    {
        while(j>0 && pattern[i] != pattern[j])
        {
            j = table[j-1];
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
    vector<int> table = make_kmp_table(pattern);
    int parent_size = parent.size();
    int pattern_size = pattern.size();
    int j = 0;
    for(int i=0; i<parent_size; ++i)
    {
        while(j>0 && parent[i]!=pattern[j])
        {
            j = table[j-1];
        }
        if(parent[i]==pattern[j])
        {
            if(j==pattern_size - 1)
            {
                cout << "Found at " << i - pattern_size + 2 <<'\n';
                //Go find next matching...
                j = table[j];
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
