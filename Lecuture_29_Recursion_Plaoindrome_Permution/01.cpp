/*
Question:
Write a recursive program to print all possible subsequences
of a given string.

Example:
Input: ABC
Output: A B C AB AC BC ABC

*/
/*
Question:
Write a recursive program to print all possible subsequences
of a given string.

Example:
Input: ABC
Output: A B C AB AC BC ABC

*/

#include<iostream>
using namespace std;

// Function to print all subsequences
void print(string s, int index, string ans){

    // Base case
    if(index == s.size()){

        // Print only non-empty subsequences
        if(ans.size())
            cout << ans << " ";

        return;
    }

    // Include current character
    print(s, index + 1, ans + s[index]);

    // Exclude current character
    print(s, index + 1, ans);
}

int main(){

    string s;

    // Taking input
    cout << "enter string:";
    cin >> s;

    // Function call
    print(s, 0, "");

    return 0;
}