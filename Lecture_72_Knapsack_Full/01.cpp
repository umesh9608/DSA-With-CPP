/*
COIN CHANGE II (Bottom-Up / Tabulation)

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
*/

#include <iostream>
#include <vector>
using namespace std;

int change(int amount, vector<int>& coins)
{
    int n = coins.size();

    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

    // Base case: One way to make amount 0
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    // Fill DP table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if (coins[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
            }
        }
    }

    return dp[n][amount];
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 5;

    cout << "Number of Ways: " << change(amount, coins);

    return 0;
}