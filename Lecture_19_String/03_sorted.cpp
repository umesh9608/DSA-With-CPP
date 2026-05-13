/*
Question:
Given a string consisting of lowercase characters,
sort the string in alphabetical order.

Example:
Input:
s = "geeksforgeeks"

Output:
eeeefggkkorss

Explanation:
Characters are arranged in sorted order.
*/

#include<iostream>
using namespace std;

int main(){

    string s;

    cin >> s;

    // size of string
    int n = s.size();

    // frequency array
    int count[26];

    // initialize array with 0
    for(int i = 0; i < 26; i++){
        count[i] = 0;
    }

    // count frequency of characters
    for(int i = 0; i < n; i++){

        int index = s[i] - 'a';

        count[index]++;
    }

    // print sorted string
    for(int i = 0; i < 26; i++){

        for(int j = 0; j < count[i]; j++){

            char c = 'a' + i;

            cout << c;
        }
    }

    return 0;
}