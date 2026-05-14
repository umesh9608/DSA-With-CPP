/* GeeksforGeeks String Question:
   Given an array of N strings,
   find the longest common prefix among all strings.
   If no common prefix exists, return "-1".

   Example:
   n = 4
   arr[] = {"geeksforgeeks", "geeks", "geek", "geezer"}

   Output:
   "gee"
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main() {

    vector<string> arr = {"geeksforgeeks", "geeks", "geek", "geezer"};
    int n = arr.size();

    int minLen = INT_MAX;

    // find minimum length string
    for(int i = 0; i < n; i++) {
        if(minLen > arr[i].size()) {
            minLen = arr[i].size();
        }
    }

    string ans = "";

    // check characters one by one
    for(int i = 0; i < minLen; i++) {

        char ch = arr[0][i];

        for(int j = 1; j < n; j++) {

            if(arr[j][i] != ch) {

                if(ans.length() > 0) {
                    cout << ans;
                }
                else {
                    cout << "-1";
                }

                return 0;
            }
        }

        ans += ch;
    }

    if(ans.length() > 0) {
        cout << ans;
    }
    else {
        cout << "-1";
    }

    return 0;
}