/*
HOUSE ROBBER (Recursion)

You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed.

The only constraint is that adjacent houses cannot be robbed.

Return the maximum amount of money you can rob without alerting the police.

Example:
Input:
nums = {2, 7, 9, 3, 1}

Output:
12

Explanation:
Rob house 1 (2), house 3 (9), and house 5 (1).
Total = 2 + 9 + 1 = 12.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive function
int find(int index, vector<int>& nums, int n)
{
    if (index >= n)
        return 0;

    // Rob current house
    int robCurrent = nums[index] + find(index + 2, nums, n);

    // Skip current house
    int skipCurrent = find(index + 1, nums, n);

    return max(robCurrent, skipCurrent);
}

// Main function
int rob(vector<int>& nums)
{
    int n = nums.size();
    return find(0, nums, n);
}

int main()
{
    vector<int> nums = {2, 7, 9, 3, 1};

    cout << "Maximum Money: " << rob(nums);

    return 0;
}