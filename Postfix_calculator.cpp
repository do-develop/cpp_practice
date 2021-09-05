#include <iostream>
#include <string>
#include <stack>
#include <sstream> //string stream library istringstream()

using namespace std;

bool isOperator(const string& input);
void performOperation(const string& input, stack<double>& calStack);

int main()
{
    cout << "=====Postfix Calculator=====\n";

    stack<double> calStack;
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
            calStack.push(num);
        }
        //check for operator
        else if(isOperator(input))
        {
            performOperation(input, calStack);
        }
        //check for quit
        else if(input == "q")
        {
            return 0; //exit program successfully
        }
        //handle invalid output
        else
        {
            cout << "Invalid input" << endl;
        }
    }
}

bool isOperator(const string& input)
{
    string ops[] = {"-", "+", "*", "/"};

    for(int i=0; i<4; ++i)
    {
        if(input == ops[i])
        {
            return true;
        }
    }

    return false;
}

void performOperation(const string& input, stack<double>& calStack)
{
    double lVal, rVal, result;

    rVal = calStack.top();
    calStack.pop();

    lVal = calStack.top();
    calStack.pop();

    //can you refactor this code (repeated code issue)?
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

    cout << result << endl;
    calStack.push(result);
}
