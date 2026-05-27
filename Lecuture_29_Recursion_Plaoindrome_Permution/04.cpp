/*
Question:
Write a recursive program to print all permutations
of a given string.

Example:
Input: ABC
Output:
ABC
ACB
BAC
BCA
CBA
CAB

*/

#include<iostream>
using namespace std;

// Function to print permutations
void print(string s, int index){

    // Base case
    if(index == s.size()){

        cout << s << endl;
        return;
    }

    // Generate permutations
    for(int i = index; i < s.size(); i++){

        // Swap current character
        swap(s[i], s[index]);

        // Recursive call
        print(s, index + 1);

        // Backtracking
        swap(s[i], s[index]);
    }
}

int main(){

    string s;

    // Taking input
    cout << "Enter string:";
    cin >> s;

    // Function call
    print(s, 0);

    return 0;
}