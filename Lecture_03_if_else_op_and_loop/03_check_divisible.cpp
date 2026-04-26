// given a number check if it is divisible by 3 & 5 ?
#include <iostream>
using namespace std;
int main()
{
    int num;
    cout << "Enter any no:";
    cin >> num;
    if (num % 3 == 0 && num % 5 == 0)
        cout << "Perfect";
    else
        cout << "Not Perfect";
    return 0;
}