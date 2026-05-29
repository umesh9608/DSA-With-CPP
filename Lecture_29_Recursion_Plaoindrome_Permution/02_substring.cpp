/*
Question:
Given a string s, the task is to print all the substrings
present inside the string.

Example:
Input: abc
Output: a ab abc b bc c

*/

#include<iostream>
using namespace std;

// Function to print substrings
void printSubstring(string s, int start, int end){

    // Base case
    if(end == s.size())
        return;

    // Print current substring
    cout << s.substr(start, end - start + 1) << " ";

    // Move end forward
    if(end + 1 < s.size())
        printSubstring(s, start, end + 1);

    // Move start forward
    else
        printSubstring(s, start + 1, start + 1);
}

int main(){

    string s;

    // Taking input
    cout << "enter string:";
    cin >> s;

    // Function call
    printSubstring(s, 0, 0);

    return 0;
}