// Question:
// Given two strings a and b.
// Check whether string b can be obtained
// by rotating string a by exactly 2 places.
//
// Example:
// Input:
// a = amazon
// b = onamaz
//
// Output:
// Yes

#include<iostream>
using namespace std;

int main() {

    string a = "amazon";
    string b = "onamaz";

    // Clockwise rotation by 2
    string clockwise = a.substr(a.size() - 2) + a.substr(0, a.size() - 2);

    // Anti-clockwise rotation by 2
    string anticlockwise = a.substr(2) + a.substr(0, 2);

    if(b == clockwise || b == anticlockwise) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

    return 0;
}