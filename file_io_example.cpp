#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //Writing
    string file_name = "sample.txt";
    ofstream outfile(file_name);

    if(outfile.is_open())
    {

        outfile << "This is my first message\nHello world!\n";

        //done writing now close outfile
        outfile.close();
        cout << "Done writing to a file\n" << endl;
    }
    else
    {
        cout << "Error writing to a file" << endl;
    }

    //Reading
    string line;
    cout<<"Read from "<< file_name << ": " << endl;
    ifstream infile(file_name);

    if(infile.is_open())
    {
        while(!infile.eof())
        {
            getline(infile, line);
            cout << line << endl;
        }
        //done reading now close infile
        infile.close();
    }
    else
    {
        cout << "Error reading from a file";
    }

    return 0;
}
