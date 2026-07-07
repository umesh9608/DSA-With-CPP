/*
HOUSE ROBBER (Bottom-Up / Tabulation)

You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money.

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

int rob(vector<int>& nums)
{
    int n = nums.size();

    vector<int> dp(n + 2, 0);

    // Bottom-Up DP
    for (int i = n - 1; i >= 0; i--)
    {
        dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
    }

    return dp[0];
}

int main()
{
    vector<int> nums = {2, 7, 9, 3, 1};

    cout << "Maximum Money: " << rob(nums);

    return 0;
}