/*Print the reverse of a number
 no: 3 2 6 5
 reverse:5 6 2 3
 */

#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter number: ";
    cin >> num;

    int sum = 0;

    while (num)
    {
        int digit = num % 10;
        sum = sum * 10 + digit;
        num = num / 10;
    }

    cout << "Reverse: " << sum;

    return 0;
}