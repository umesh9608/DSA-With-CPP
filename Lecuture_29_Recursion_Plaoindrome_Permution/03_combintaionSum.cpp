/*
Question:
Given an array of distinct integers candidates and a target integer target,
return all unique combinations of candidates where the chosen numbers sum to target.

You may use the same element multiple times.

Example:
Input:
candidates = {2,3,6,7}
target = 7

Output:
{2,2,3}
{7}

*/

#include<iostream>
#include<vector>
using namespace std;

// Function to find combinations
void find(vector<int>& candidates,
          vector<vector<int>>& ans,
          vector<int> temp,
          int sum,
          int target,
          int index){

    // Base case
    if(index == candidates.size()){

        // If target achieved
        if(sum == target)
            ans.push_back(temp);

        return;
    }

    // If sum exceeds target
    if(sum > target)
        return;

    // Exclude current element
    find(candidates, ans, temp, sum, target, index + 1);

    // Include current element
    sum += candidates[index];
    temp.push_back(candidates[index]);

    // Same index because element can be reused
    find(candidates, ans, temp, sum, target, index);
}

// Function to return all combinations
vector<vector<int>> combinationsSum(vector<int>& candidates, int target){

    vector<vector<int>> ans;
    vector<int> temp;
    int sum = 0;

    find(candidates, ans, temp, sum, target, 0);

    return ans;
}

int main(){

    vector<int> candidates = {2,3,6,7};
    int target = 7;

    vector<vector<int>> ans = combinationsSum(candidates, target);

    // Printing answer
    for(int i = 0; i < ans.size(); i++){

        cout << "{ ";

        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }

        cout << "}" << endl;
    }

    return 0;
}