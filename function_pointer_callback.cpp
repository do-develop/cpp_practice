#include <iostream>

using namespace std;
//Common usage of funciton pointer --> callback function
//Passing functions as arguments to other functions
//https://www.oreilly.com/library/view/c-cookbook/0596007612/ch15s02.html

void updateProgress(int percent)
{
    cout << percent << "% complete...\n";
    //return (true);
}

//to make it less ugly...
typedef void(*fcnPtr)(int);

void longOperation(fcnPtr fptr) //to simulate an operation that takes awhile
{
    for(long l=0; l<=100000000; ++l)
        if(l % 10000000 == 0)
            fptr(l / 1000000);
}

int main()
{
    longOperation(updateProgress);

    return 0;
}
