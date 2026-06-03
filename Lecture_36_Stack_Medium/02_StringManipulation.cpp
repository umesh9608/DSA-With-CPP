/*
STRING MANIPULATION

Tom is a string freak. He has got sequences of words to manipulate.
If in a sequence, two same words come together then they'll
destroy each other.

Find the number of words left in the sequence after pairwise destruction.

Input:
N = 5
v[] = {"ab", "aa", "aa", "bcd", "ab"}

Output:
3
*/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int stringManipulation(vector<string>& v){

    stack<string> s;

    for(int i=0;i<v.size();i++){

        if(!s.empty() && s.top()==v[i]){
            s.pop();
        }
        else{
            s.push(v[i]);
        }
    }

    return s.size();
}

int main(){

    vector<string> v={"ab","aa","aa","bcd","ab"};

    cout<<stringManipulation(v);

    return 0;
}