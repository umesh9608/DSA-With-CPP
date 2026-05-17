// Question:
// Given a string, find the length of the Longest Prefix Suffix (LPS).
// LPS means the longest proper prefix which is also a suffix.


//eg :-ababcabength is :2
#include<iostream>
#include<vector>
using namespace std;

int main() {

    string s;

    cout << "Enter string: ";
    cin >> s;

    vector<int> lps(s.size(), 0);

    int first = 0;
    int second = 1;

    while(second < s.size()) {

        if(s[first] == s[second]) {

            first++;
            lps[second] = first;
            second++;

        } else {

            if(first == 0) {

                lps[second] = 0;
                second++;

            } else {

                first = lps[first - 1];
            }
        }
    }

    cout << "LPS Length = " << lps[s.size() - 1];

    return 0;
}