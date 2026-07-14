/*
BEST TIME TO BUY AND SELL STOCK III

You are given an array prices where prices[i] is the price of a stock
on the ith day.

Find the maximum profit you can achieve by making at most
two transactions.

Note:
- You must sell the stock before buying again.

Example:
Input:
prices = {3,3,5,0,0,3,1,4}

Output:
6

Explanation:
Buy at 0, Sell at 3
Buy at 1, Sell at 4
Total Profit = 6
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MaxProfit(vector<int>& prices)
{
    int n = prices.size();

    vector<vector<int>> dp(3, vector<int>(n + 1, 0));

    for (int i = 1; i <= 2; i++)
    {
        int total = -prices[0];

        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = max(dp[i][j - 1], prices[j - 1] + total);

            total = max(total, dp[i - 1][j] - prices[j - 1]);
        }
    }

    return dp[2][n];
}

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

    cout << "Maximum Profit: " << MaxProfit(prices);

    return 0;
}