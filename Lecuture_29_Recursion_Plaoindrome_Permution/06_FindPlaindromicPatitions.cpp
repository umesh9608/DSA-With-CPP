/*
Question:
Find all possible palindromic partitions of a string.

Given a string s, print all possible partitions such that
every substring of the partition is a palindrome.

Example:
Input: s = "geeks"

Output:
g e e k s
g ee k s

Explanation:
All possible palindromic partitions are printed.

*/

#include<iostream>
#include<vector>
using namespace std;

// Function to check palindrome
bool isPalindrome(string s, int start, int end){

    while(start < end){

        if(s[start] != s[end])
            return false;

        start++;
        end--;
    }

    return true;
}

// Recursive function
void solve(string s,
           vector<string>& temp,
           vector<vector<string>>& ans,
           int index){

    // Base case
    if(index == s.size()){

        ans.push_back(temp);
        return;
    }

    // Generate partitions
    for(int i = index; i < s.size(); i++){

        // Check palindrome
        if(isPalindrome(s, index, i)){

            // Add substring
            temp.push_back(s.substr(index, i - index + 1));

            // Recursive call
            solve(s, temp, ans, i + 1);

            // Backtracking
            temp.pop_back();
        }
    }
}

int main(){

    string s;

    // Taking input
    cout << "Enter string:";
    cin >> s;

    vector<vector<string>> ans;
    vector<string> temp;

    // Function call
    solve(s, temp, ans, 0);

    // Printing answer
    for(int i = 0; i < ans.size(); i++){

        for(int j = 0; j < ans[i].size(); j++){

            cout << ans[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}