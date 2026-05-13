/*
Question:
Given two strings denoting non-negative numbers X and Y,
calculate the sum of X and Y.

Example:
Input:
X = "1234"
Y = "567"

Output:
1801

Explanation:
1234 + 567 = 1801
*/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){

    // input strings
    string X = "1234";
    string Y = "567";

    // last indexes
    int Xend = X.size() - 1;
    int Yend = Y.size() - 1;

    string ans = "";

    int num, rem, carry = 0;

    char c;

    // add both strings
    while(Xend >= 0 && Yend >= 0){

        num = (X[Xend] - '0') + (Y[Yend] - '0') + carry;

        rem = num % 10;

        carry = num / 10;

        c = rem + '0';

        ans += c;

        Xend--;
        Yend--;
    }

    // remaining digits of X
    while(Xend >= 0){

        num = (X[Xend] - '0') + carry;

        rem = num % 10;

        carry = num / 10;

        c = rem + '0';

        ans += c;

        Xend--;
    }

    // remaining digits of Y
    while(Yend >= 0){

        num = (Y[Yend] - '0') + carry;

        rem = num % 10;

        carry = num / 10;

        c = rem + '0';

        ans += c;

        Yend--;
    }

    // if carry remains
    if(carry){

        ans += (carry + '0');
    }

    // reverse answer
    reverse(ans.begin(), ans.end());

    // print answer
    cout << "Sum = " << ans;

    return 0;
}