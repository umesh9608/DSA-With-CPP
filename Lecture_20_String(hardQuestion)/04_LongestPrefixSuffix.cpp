/* GeeksforGeeks String Question:
   Given a string, find the length of the
   longest proper prefix which is also suffix.

   Example:
   Input : s = "abab" 
   Output : 2
*/

#include<iostream>
using namespace std;

int main(){

    string s = "abab";

    int index[s.size() + 1];
    char str[s.size() + 1];

    // store string in char array
    for(int i = 0; i < s.size(); i++){

        str[i + 1] = s[i];

        index[i] = 0;
    }

    index[s.size()] = 0;

    int first = 0;
    int second = 2;

    // build LPS array
    while(second <= s.size()){

        if(str[first + 1] == str[second]){

            first++;

            index[second - 1] = first;

            second++;
        }
        else{

            if(first == 0){

                index[second - 1] = 0;

                second++;
            }
            else{

                first = index[first - 1];
            }
        }
    }

    // print LPS array
    for(int i = 0; i < s.size(); i++){
        cout << index[i] << " ";
    }

    cout << endl;

    // answer
    cout << "Longest Prefix Suffix Length = "
         << index[s.size() - 1];

    return 0;
}