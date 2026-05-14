//print n natural number
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    // Loop starts from 1 and goes up to n
    for (int i = 1; i <= n; i++) {
        cout << i << " "; // Prints the current number followed by a space
    }

    return 0;
}
