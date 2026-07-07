/*
HOUSE ROBBER (Top-Down DP / Memoization)

You are a professional robber planning to rob houses along a street.
Each house contains some amount of money.

You cannot rob two adjacent houses.

Return the maximum amount of money you can rob.

Example:
Input:
nums = {2, 7, 9, 3, 1}

Output:
12

Explanation:
Rob houses with money 2, 9, and 1.
Total = 12.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Top-Down DP (Memoization)
int find(int index, vector<int>& nums, int n, vector<int>& dp)
{
    if (index >= n)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int robCurrent = nums[index] + find(index + 2, nums, n, dp);
    int skipCurrent = find(index + 1, nums, n, dp);

    return dp[index] = max(robCurrent, skipCurrent);
}

int rob(vector<int>& nums)
{
    int n = nums.size();

    vector<int> dp(n + 2, -1);

    return find(0, nums, n, dp);
}

int main()
{
    vector<int> nums = {2, 7, 9, 3, 1};

    cout << "Maximum Money: " << rob(nums);

    return 0;
}