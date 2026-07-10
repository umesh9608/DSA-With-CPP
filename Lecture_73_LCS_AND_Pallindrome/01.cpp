/*
0/1 KNAPSACK PROBLEM (Space Optimized DP)

Given weights[] and values[] of N items, and a knapsack of capacity W,
find the maximum total value that can be put into the knapsack.

Each item can be taken at most once.

Example:
Input:
N = 3
W = 4
weights = {4, 5, 1}
values = {1, 2, 3}

Output:
3

Explanation:
Take the item with weight 1 and value 3.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int W, int wt[], int val[], int n)
{
    vector<int> dp(W + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        // Traverse from right to left
        for (int j = W; j >= 0; j--)
        {
            if (wt[i - 1] <= j)
            {
                dp[j] = max(dp[j], val[i - 1] + dp[j - wt[i - 1]]);
            }
        }
    }

    return dp[W];
}

int main()
{
    int W = 4;
    int wt[] = {4, 5, 1};
    int val[] = {1, 2, 3};
    int n = 3;

    cout << "Maximum Value: " << knapsack(W, wt, val, n);

    return 0;
}