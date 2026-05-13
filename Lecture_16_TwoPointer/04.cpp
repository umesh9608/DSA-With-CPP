/*
Question:
Find the continuous subarray whose sum is equal to S.

Return the starting and ending position (1-based indexing).

Example:
Input:
arr[] = {1, 2, 3, 7, 5}
S = 12

Output:
2 4

Explanation:
2 + 3 + 7 = 12
*/

#include<iostream>
#include<vector>
using namespace std;

int main(){

    // array
    int arr[] = {1, 2, 3, 7, 5};

    // size of array
    int n = 5;

    // target sum
    int s = 12;

    vector<int> ans;

    // if sum is 0
    if(s == 0){

        ans.push_back(-1);

        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }

        return 0;
    }

    // sliding window
    int l = 0;
    int r = 0;

    int countsum = arr[0];

    bool isTrue = false;

    while(r < n){

        // sum found
        if(countsum == s){

            isTrue = true;
            break;
        }

        // increase window
        else if(countsum < s){

            r++;

            if(r < n){
                countsum += arr[r];
            }
        }

        // shrink window
        else{

            countsum -= arr[l];
            l++;
        }
    }

    // print answer
    if(isTrue == true){

        ans.push_back(l + 1);
        ans.push_back(r + 1);

        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
    }

    else{
        ans.push_back(-1);

        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
    }

    return 0;
}