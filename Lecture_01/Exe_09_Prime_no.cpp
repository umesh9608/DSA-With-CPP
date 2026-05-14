//check for prime number
/*
-> take input n
-> take initial = 2;
-> check n % initial == 0;
-> if 0 then print not prime , return
-> else prime
-> initial ++;
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    bool isPrime = true;

    cout << "Enter n: ";
    cin >> n;

    // Numbers less than 2 are not prime
    if (n < 2) {
        isPrime = false;
    } else {
        // Loop starts from 2 and goes up to n-1
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                isPrime = false; // Found a divisor
                break;           // No need to check further
            }
        }
    }

    if (isPrime) {
        cout << n << " is a prime number." << endl;
    } else {
        cout << n << " is not a prime number." << endl;
    }

    return 0;
}
