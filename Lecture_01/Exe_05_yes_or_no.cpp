//You got an offerletter from  X company . you will accept offer only when pagckage is greater than 10LPA
#include <iostream>
using namespace std;

int main() {
    double package;

    cout << "Enter the offered package (in LPA): ";
    cin >> package;

    // Check if package is greater than 10
    if (package > 10) {
        cout << "Offer Accepted! It's greater than 10 LPA." << endl;
    } else {
        cout << "Offer Rejected. The package must be more than 10 LPA." << endl;
    }

    return 0;
}
