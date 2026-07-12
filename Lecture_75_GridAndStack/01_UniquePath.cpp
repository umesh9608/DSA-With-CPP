/*
UNIQUE PATHS (Bottom-Up / Tabulation)

Given two integers n and m representing the number of rows and columns
of a grid, return the number of unique paths from the top-left corner
to the bottom-right corner.

You can only move either:
1. Right
2. Down

Example:
Input:
n = 3
m = 3

Output:
6

Explanation:
There are 6 unique paths.
*/

#include <iostream>
#include <vector>
using namespace std;

int NumberOfPath(int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m, 1));

    // Fill the DP table from bottom-right to top-left
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = m - 2; j >= 0; j--)
        {
            dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
        }
    }

    return dp[0][0];
}

int main()
{
    int n, m;

    cout << "Enter rows and columns: ";
    cin >> n >> m;

    cout << "Number of Unique Paths: " << NumberOfPath(n, m) << endl;

    return 0;
}