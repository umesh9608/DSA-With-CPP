/* 
Question:
Give a string str. The task is to find the maximum occurring character 
in the string str. If more than one character occurs the maximum number 
of times, then print the lexicographically smaller character.
*/

#include<iostream>
#include<string>
using namespace std;

int main() {

    string str = "programming";

    int freq[26] = {0};

    // count frequency
    for(int i = 0; i < str.size(); i++) {
        freq[str[i] - 'a']++;
    }

    int maxFreq = 0;
    char ans;

    // find maximum occurring character
    for(int i = 0; i < 26; i++) {
        if(freq[i] > maxFreq) {
            maxFreq = freq[i];
            ans = i + 'a';
        }
    }

    cout << "Maximum occurring character: " << ans;

    return 0;
}