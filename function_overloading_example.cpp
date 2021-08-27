#include <iostream>
#include <string>

//function overloading example
using namespace std;

void printValue(int value);
void printValue(string type, int value);
int main()
{
    printValue(100);
    printValue("Step count", 1000);
    return 0;
}

void printValue(int value)
{
    cout << "Value: " << value << endl;
}

void printValue(string type, int value)
{
    cout << "Type: " << type <<
            ", Value: " << value << endl;
}
