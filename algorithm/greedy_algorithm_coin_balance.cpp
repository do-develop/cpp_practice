#include <iostream>

using namespace std;

int main(void)
{
    int balance, result = 0;
    cin >> balance;

    result += balance/500;
    balance %= 500;
    result += balance/100;
    balance %= 100;
    result += balance/50;
    balance %= 50;
    result += balance/10;

    cout << result;
}
