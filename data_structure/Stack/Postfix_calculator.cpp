#include <iostream>
#include "Stack.h"
#include <sstream> //string stream library isstringsteam()
// to stream into a different variable
using namespace std;

bool isOperator(const string& input);
void performOperation(const string& input, Stack<double>& calStack);

int main()
{
    cout << "=====Postfix Calculator=====\n";

    Stack<double> calStack;
    string input;

    while(true)
    {
        //display prompt
        cout << ">>";
        //get input
        cin >> input;

        //check for numeric value
        double num;
        if(istringstream(input) >> num)
        {
            calStack.Push(num);
        }
        else if(isOperator(input))
        {
            performOperation(input, calStack);
        }
        else if(input == "q")
        {
            return 0; //exit program successfully
        }
        else
        {
            cout << "Invalid Input!\n";
        }
    }

    return 0;
}

bool isOperator(const string& input)
{
    string ops[] = {"-", "+", "*", "/"};
    for(int i=0; i<4; ++i)
    {
        if(input == ops[i])
            return true;
    }
    return false;
}
void performOperation(const string& input, Stack<double>& calStack)
{
    double lVal, rVal, result;

    if(!calStack.Pop(rVal) || !calStack.Pop(lVal))
        return;

    if(input == "-")
    {
        result = lVal - rVal;
    }
    else if(input == "+")
    {
        result = lVal + rVal;
    }
    else if(input == "*")
    {
        result = lVal * rVal;
    }
    else
    {
        result = lVal / rVal;
    }

    cout << result << '\n';
    calStack.Push(result);
}

