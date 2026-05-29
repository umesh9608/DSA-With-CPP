/*
Question:
Given a string digits containing digits from 2-9 inclusive,
return all possible letter combinations that the number could represent.

A mapping of digits to letters (like telephone buttons) is given below:
2 -> abc
3 -> def
4 -> ghi
5 -> jkl
6 -> mno
7 -> pqrs
8 -> tuv
9 -> wxyz

Example:
Input: "23"
Output:
ad ae af bd be bf cd ce cf

*/

#include<iostream>
#include<vector>
using namespace std;

// Recursive function
void fun(string &digits,
         vector<string>& answer,
         vector<string>& mapping,
         string temp,
         int index){

    // Base case
    if(index == digits.size()){

        answer.push_back(temp);
        return;
    }

    // Find mapping position
    int pos = digits[index] - '2';

    // Traverse mapped characters
    for(int i = 0; i < mapping[pos].size(); i++){

        fun(digits,
            answer,
            mapping,
            temp + mapping[pos][i],
            index + 1);
    }
}

// Function to return combinations
vector<string> letterCombination(string digits){

    vector<string> answer;

    // If input string is empty
    if(digits.size() == 0)
        return answer;

    // Mapping for digits
    vector<string> mapping(8);

    mapping[0] = "abc";
    mapping[1] = "def";
    mapping[2] = "ghi";
    mapping[3] = "jkl";
    mapping[4] = "mno";
    mapping[5] = "pqrs";
    mapping[6] = "tuv";
    mapping[7] = "wxyz";

    // Recursive call
    fun(digits, answer, mapping, "", 0);

    return answer;
}

int main(){

    string digits;

    // Taking input
    cout << "Enter digits:";
    cin >> digits;

    // Function call
    vector<string> ans = letterCombination(digits);

    // Printing answer
    for(int i = 0; i < ans.size(); i++){

        cout << ans[i] << " ";
    }

    return 0;
}