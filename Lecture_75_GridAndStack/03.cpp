/*
UNIQUE PATHS II (Obstacle Grid)

Given a grid of size n × m where:
1 -> Free cell
0 -> Blocked cell

Find the number of unique paths from the top-left corner
to the bottom-right corner.

You can move only:
1. Right
2. Down

Return the answer modulo 1000000007.

Example:
Input:
1 1 1
1 0 1
1 1 1

Output:
2
*/

#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int uniquePath(int n, int m, vector<vector<int>>& grid)
{
    // Start or destination blocked
    if (grid[0][0] == 0 || grid[n - 1][m - 1] == 0)
        return 0;

    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Destination
    dp[n - 1][m - 1] = 1;

    // Last row
    for (int j = m - 2; j >= 0; j--)
    {
        if (grid[n - 1][j] == 1)
            dp[n - 1][j] = dp[n - 1][j + 1];
        else
            break;
    }

    // Last column
    for (int i = n - 2; i >= 0; i--)
    {
        if (grid[i][m - 1] == 1)
            dp[i][m - 1] = dp[i + 1][m - 1];
        else
            break;
    }

    // Fill remaining cells
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = m - 2; j >= 0; j--)
        {
            if (grid[i][j] == 1)
            {
                dp[i][j] = (dp[i + 1][j] + dp[i][j + 1]) % MOD;
            }
        }
    }

    return dp[0][0];
}

int main()
{
    int n, m;

    cout << "Enter rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    cout << "Enter grid (1 = Free, 0 = Blocked):\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    cout << "Unique Paths = " << uniquePath(n, m, grid);

    return 0;
}