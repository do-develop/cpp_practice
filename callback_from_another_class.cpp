#include <iostream>

using namespace std;

//how to callback a member method inside a class?
class MyClass
{
public:
    void MemberMethod(int arg)
    {
        cout << "Passed argument: " << arg << endl;
    }

    //answer: define a static method to allow main(void) to to access this
    static void CallBackMethod(MyClass* myObj, int arg)
    {
        if(myObj)
        {
            myObj->MemberMethod(arg);
        }
    }

};

//how to callback a member method insdie a class from antoher class

class Callee
{
public:
    int callbackFunction(int i)
    {
        cout << "\tInside of callbackFunction()\n";
        return i;
    }
    //this is the function that will be called by the Caller
    static int staticCallbackFunction(void* ptr, int i)
    {
        ((Callee*)ptr) -> callbackFunction(i);
    }
};

typedef int(*CallbackFunctionPtr)(void*, int);

class Caller
{
private:
    CallbackFunctionPtr m_cb;
    void* m_ptr;
public:
    void connectCallback(CallbackFunctionPtr cbPtr, void* ptr)
    {
        m_cb = cbPtr; //callee static callback function
        m_ptr = ptr; //callee
    }
    //to test the callback
    void test()
    {
        cout << "Caller::test() calls the callback function\n";
        int result = m_cb(m_ptr, 10);
        cout << "\t\tResult: " << result << "\n";
    }
};



int main(void)
{
    //calling inside own class
    MyClass myC;
    myC.CallBackMethod(&myC, 10);

    //calling from other class
    Caller caller;
    Callee callee;

    caller.connectCallback(Callee::staticCallbackFunction, &callee);
    caller.test();

    return 0;
}
