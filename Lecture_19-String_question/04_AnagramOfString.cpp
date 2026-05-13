/*
Question:
Given two strings S1 and S2 in lowercase, the task is to make them anagram.
The only allowed operation is to remove a character from any string.

Find the minimum number of characters to be deleted to make both strings anagram.

Two strings are called anagram of each other if one of them can be converted
into another by rearranging its letters.
*/

#include<iostream>
#include<string>
using namespace std;

int main() {

    string s1 = "bcadeh";
    string s2 = "hea";

    int freq[26] = {0};

    // count frequency of s1
    for(int i = 0; i < s1.size(); i++) {
        freq[s1[i] - 'a']++;
    }

    // subtract frequency of s2
    for(int i = 0; i < s2.size(); i++) {
        freq[s2[i] - 'a']--;
    }

    int deletions = 0;

    // count total deletions
    for(int i = 0; i < 26; i++) {
        deletions += abs(freq[i]);
    }

    cout << "Minimum deletions required: " << deletions;

    return 0;
}