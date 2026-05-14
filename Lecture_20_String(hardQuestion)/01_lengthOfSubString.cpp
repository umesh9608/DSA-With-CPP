/*
Question:
Given a string S, find the length of the
longest substring without repeating characters.

Example:
Input:
S = "geeksforgeeks"

Output:
7

Explanation:
The longest substring without repeating
characters is "eksforg" whose length is 7.
*/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){

    // input string
    string S = "geeksforgeeks";

    // frequency array
    bool count[26] = {0};

    // sliding window pointers
    int first = 0;
    int second = 1;

    // maximum length
    int total = 1;

    // mark first character
    count[S[0] - 'a'] = 1;

    while(second < S.size()){

        // remove repeated characters
        while(count[S[second] - 'a']){

            count[S[first] - 'a'] = 0;

            first++;
        }

        // mark current character
        count[S[second] - 'a'] = 1;

        // update maximum length
        total = max(total, second - first + 1);

        second++;
    }

    // print answer
    cout << "Longest Substring Length = " << total;

    return 0;
}

//t.c : o(n)