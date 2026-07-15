/*
EGG DROPPING PUZZLE (Bottom-Up / Tabulation)

You are given:
- n eggs
- k floors

Find the minimum number of attempts required in the worst case
to determine the highest floor from which an egg can be dropped
without breaking.

Example:
Input:
n = 2
k = 10

Output:
4
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int eggDrop(int n, int k)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    // Base case: One egg
    for (int j = 0; j <= k; j++)
    {
        dp[1][j] = j;
    }

    // Fill DP table
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            int ans = INT_MAX;

            for (int a = 1; a <= j; a++)
            {
                int temp = 1 + max(dp[i - 1][a - 1], dp[i][j - a]);
                ans = min(ans, temp);
            }

            dp[i][j] = ans;
        }
    }

    return dp[n][k];
}

int main()
{
    int eggs, floors;

    cout << "Enter number of eggs: ";
    cin >> eggs;

    cout << "Enter number of floors: ";
    cin >> floors;

    cout << "Minimum Attempts: " << eggDrop(eggs, floors) << endl;

    return 0;
}