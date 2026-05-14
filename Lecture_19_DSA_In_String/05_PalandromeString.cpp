/*
Question:
Given a string S, check if it is palindrome or not.
A palindrome string reads the same forward and backward.
*/

#include<iostream>
#include<string>
using namespace std;

int main() {

    string S = "naman";

    int start = 0;
    int end = S.size() - 1;

    bool isPalindrome = true;

    while(start < end) {

        if(S[start] != S[end]) {
            isPalindrome = false;
            break;
        }

        start++;
        end--;
    }

    if(isPalindrome) {
        cout << "Palindrome";
    }
    else {
        cout << "Not Palindrome";
    }

    return 0;
}