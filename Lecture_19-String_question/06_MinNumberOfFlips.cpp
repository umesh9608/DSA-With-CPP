/*
Question:
Given a binary string, that is it contains only 0s and 1s.
We need to make this string a sequence of alternate characters
by flipping some of the bits.

Our goal is to minimize the number of bits to be flipped.
*/

#include<iostream>
#include<string>
using namespace std;

int main() {

    string S = "0001010111";

    int count1 = 0;
    int count2 = 0;

    bool flag = 0;

    // Pattern starting with 0 -> 010101...
    for(int i = 0; i < S.size(); i++) {

        if((S[i] - '0') != flag) {
            count1++;
        }

        flag = !flag;
    }

    flag = 1;

    // Pattern starting with 1 -> 101010...
    for(int i = 0; i < S.size(); i++) {

        if((S[i] - '0') != flag) {
            count2++;
        }

        flag = !flag;
    }

    cout << "Minimum flips required: " << min(count1, count2);

    return 0;
}