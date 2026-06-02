#include<iostream>
#include<stack>
using namespace std;

/*
Question:
Redundant Braces

Given a string A representing an expression,
determine whether the expression contains
redundant braces or not.

Return:
1 -> If redundant braces exist
0 -> If redundant braces do not exist

Example:

Input:  ((a+b))
Output: 1

Explanation:
Extra brackets are present.

Input: (a+(a+b))
Output: 0

Explanation:
No unnecessary brackets exist.
*/

int braces(string A){

    stack<char> s;

    int n = A.length();

    for(int i=0; i<n; i++){

        // Push every character except ')'
        if(A[i] != ')'){
            s.push(A[i]);
        }

        else{

            int count = 0;

            // Count elements inside brackets
            while(!s.empty() && s.top()!='('){
                count++;
                s.pop();
            }

            // Remove opening bracket
            if(!s.empty()){
                s.pop();
            }

            // If less than 2 elements inside braces
            // then braces are redundant
            if(count < 2){
                return 1;
            }

            // Push dummy character
            s.push('a');
        }
    }

    return 0;
}

int main(){

    string A = "((a+b))";

    cout << braces(A);

    return 0;
}