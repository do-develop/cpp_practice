#include <iostream>
#include <string.h>

using namespace std;

class Timer{

private:
    int minute;
    int second;
    int* data; //dummy data to simulate a dynamically allocated memory

public:
    //constructor
    Timer(){
        data = new int;
    }
    //destructor
    ~Timer(){
        delete data;
    }
    //copy method
    void Copy(const Timer& otherTimer)
    {
        minute = otherTimer.minute;
        second = otherTimer.second;
        data = new int(*otherTimer.data);
    }
    //copy constructor
    Timer(Timer &otherTimer)
    {
        Copy(otherTimer);
    }
    //assignment operator
    Timer &operator = (const Timer& otherTimer){
        Copy(otherTimer);
    }
    //setter
    void setTimer(int m, int s, int d){
        minute = m;
        second = s;
        *data = d;
    }
    //io method inside a class is not a good practice
    //below is just for demonstration purpose
    void showTimer(){
        cout << minute << ":" <<second << " (" << *data << ")"<<endl;
    }

};

int main()
{
    //============================copy constructor==========================//
    Timer t1;

    t1.setTimer(1, 11, 1);
    cout << "timer_1 ";
    t1.showTimer();


    Timer t2 = t1; //Default copy constructor (created by compiler) is called
    cout << "timer_2 ";
    t2.showTimer();


    //Deep copy (the changes in cloned object does not affect the original object)
    t2.setTimer(2, 22, 2);
    cout << "timer_1 ";
    t1.showTimer();


    //======================copy assignment operator========================//
    Timer t3;
    t3.setTimer(3, 33, 3);
    cout << "\ntimer_3 ";
    t3.showTimer();

    Timer t4;
    //as there is no user-defined copy assignment operator,
    //the compiler will call an inline public member of the class
    //(copy assignment operator is overloaded by the compiler)
    t4 = t3;
    cout << "timer_4 ";
    t4.showTimer();


    //Deep copy (the changes in cloned object does not affect the original object)
    t4.setTimer(4, 44, 4);
    cout << "timer_3 ";
    t3.showTimer();

    return 0;
}
