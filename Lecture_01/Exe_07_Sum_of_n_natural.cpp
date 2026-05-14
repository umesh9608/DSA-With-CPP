//sum of n natural number
/*
-> take input
-> take 1 by 1 number in sum
-> add the number in sum
-> pepeat this process until n reached
 */

#include <iostream>
using namespace std;

int main() {
    int number, sum = 0;
    cout << "Enter the number: ";
    cin >> number;

    for (int i = 1; i <= number; i++) {
        sum += i; // Adds 1, then 2, then 3... up to 'number'
    }

    cout << "Sum: " << sum;
    return 0;
}
