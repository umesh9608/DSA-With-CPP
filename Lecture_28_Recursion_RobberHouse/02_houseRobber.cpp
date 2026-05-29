#include<iostream>
#include<vector>
using namespace std;

/*
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed.

All houses at this place are arranged in a circle.
That means the first house is the neighbor of the last one.

Meanwhile, adjacent houses have a security system connected,
and it will automatically contact the police if two adjacent
houses were broken into on the same night.

Given an integer array nums representing the amount of money
of each house, return the maximum amount of money you can rob
tonight without alerting the police.

Example:
Input:
nums = [2,3,2]

Output:
3

Explanation:
You cannot rob house 1 (money = 2) and house 3 (money = 2),
because they are adjacent houses.
*/

void find(vector <int>&nums,int i, int &sum,int curr_sum){

  if(i >= nums.size()){
    sum = max(sum, curr_sum);
    return;
  }

  find(nums, i+2, sum, curr_sum+nums[i]);

  find(nums, i+1, sum, curr_sum);
}

int rob(vector<int>&nums){

  if(nums.size()==1)
    return nums[0];

  int sum=0,curr_sum=0;

  // Exclude first house
  find(nums,1,sum,curr_sum);

  curr_sum=0;

  // Exclude last house
  nums.pop_back();

  find(nums,0,sum,curr_sum);

  return sum;
}

int main(){

  vector<int> nums = {2,3,2};

  cout << rob(nums);

  return 0;
}