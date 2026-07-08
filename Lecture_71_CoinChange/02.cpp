/*
COIN CHANGE II (Top-Down / Memoization)

You are given an integer array coins representing different coin
denominations and an integer amount.

Return the number of combinations that make up that amount.

You may use each coin an unlimited number of times.

Example:
Input:
coins = {1, 2, 5}
amount = 5

Output:
4

Explanation:
The combinations are:
1+1+1+1+1
1+1+1+2
1+2+2
5
*/

#include <iostream>
#include <vector>
using namespace std;

// Memoization Function
int find(int index, int amount, vector<int>& coins, vector<vector<int>>& dp)
{
    if (amount == 0)
        return 1;

    if (index < 0)
        return 0;

    if (dp[index][amount] != -1)
        return dp[index][amount];

    if (coins[index] > amount)
    {
        return dp[index][amount] =
            find(index - 1, amount, coins, dp);
    }
    else
    {
        return dp[index][amount] =
            find(index, amount - coins[index], coins, dp) +
            find(index - 1, amount, coins, dp);
    }
}

int change(int amount, vector<int>& coins)
{
    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

    return find(n - 1, amount, coins, dp);
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 5;

    cout << "Number of Ways: " << change(amount, coins);

    return 0;
}