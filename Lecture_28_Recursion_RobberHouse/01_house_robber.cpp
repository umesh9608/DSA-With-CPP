#include<iostream>
#include<vector>
using namespace std;

/*
You are a professional robber planning to rob houses along a street.
Each house has certain amount of money stashed.

The only constraint stopping you from robbing each of them is that
adjacent houses have security systems connected and it will automatically
contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house,
return the maximum amount of money you can rob tonight without alerting the police.

Example:
nums = [1,2,3,1]

Output:
4

Explanation:
Rob house 1 (money = 1) and rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
*/

void find(vector <int>&nums,int i, int &sum,int curr_sum){

  if(i >= nums.size()){
    sum = max(sum, curr_sum);
    return;
  }

  find(nums, i+2, sum, curr_sum + nums[i]);

  find(nums, i+1, sum, curr_sum);
}

int rob(vector<int>&nums){

  int sum = 0, curr_sum = 0;

  find(nums, 0, sum, curr_sum);

  return sum;
}

int main(){

  vector<int> nums = {1,2,3,1};

  cout << rob(nums);

  return 0;
}