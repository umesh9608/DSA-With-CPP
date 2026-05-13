/*
Question:
Given a binary string S. The task is to count the number of substrings
that start and end with 1.

Example:
Input:  "00100101"
Output: 3
Substrings are: "1001", "100101", "101"
*/

#include<iostream>
#include<string>
using namespace std;

int main() {

    string str = "00100101";

    int count = 0;

    // count number of 1's
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '1') {
            count++;
        }
    }

    // number of substrings
    int ans = (count * (count - 1)) / 2;

    cout << "Total Substrings: " << ans;

    return 0;
}