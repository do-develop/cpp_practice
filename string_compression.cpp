#include <iostream>
#include <string>

using namespace std;

string compress_str(string str)
{
    int j = 0;
    string cmp_str = "";

    for(int i=0; i < str.length(); ++i)
    {
        int count = 1;
        while(i < str.length()-1 && str[i]==str[i+1])
        {
            count++;
            i++;
        }
        if(count==1)
        {
            cmp_str += str[i];
        }
        else
        {
            cmp_str += str[i];
            cmp_str += to_string(count);
        }

    }
    return cmp_str;
}

int main()
{
    string str = "aaaabbbcccccccddeefghhhiijjk";
    string compressed_str = compress_str(str);

    cout << compressed_str << endl;

    return 0;
}
