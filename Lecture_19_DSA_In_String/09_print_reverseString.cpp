#include<iostream>
#include<string>
using namespace std;

/*
Question:
Write a C++ program to reverse a string using two-pointer approach.
*/

int main() {
    string str = "hello";

    int start = 0;
    int end = str.size() - 1;

    while(start < end) {
        swap(str[start], str[end]);
        start++;
        end--;
    }
    cout << "Reverse String: " << str;
    return 0;
}