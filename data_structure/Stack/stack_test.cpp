#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    Stack<string> strStack;

    strStack.Push("August");
    strStack.Push("September");
    strStack.Push("October");
    strStack.Push("November");
    strStack.Push("December");

    string topString;
    strStack.Pop(topString);

    cout<<"\n-----After 5 Push() and 1 Pop()-----"<<endl;
 	cout << "Top element is: " << topString << endl;

 	cout << strStack.Empty() <<'\n';
 	//Pop 4 more times
	for(int i=0; i<4; ++i)
    {
        strStack.Pop(topString);
        cout << "Pop item -> " + topString << endl;
    }

	cout << strStack.Empty();

    return 0;
}
