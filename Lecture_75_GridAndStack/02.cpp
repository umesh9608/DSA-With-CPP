/*
UNIQUE PATHS (Space Optimized DP)

Given a grid of size n × m, find the number of unique paths
from the top-left corner to the bottom-right corner.

You can only move:
1. Right
2. Down

Example:
Input:
n = 3
m = 3

Output:
6
*/

#include <iostream>
#include <vector>
using namespace std;

int NumberOfPath(int n, int m)
{
    vector<int> dp(m, 1);

    // Fill from bottom to top
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = m - 2; j >= 0; j--)
        {
            dp[j] = dp[j] + dp[j + 1];
        }
    }

    return dp[0];
}

int main()
{
    int n, m;

    cout << "Enter rows and columns: ";
    cin >> n >> m;

    cout << "Number of Unique Paths: " << NumberOfPath(n, m) << endl;

    return 0;
}