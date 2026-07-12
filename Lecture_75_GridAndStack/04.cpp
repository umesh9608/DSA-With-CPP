/*
MINIMUM PATH SUM

Given a grid filled with non-negative numbers, find a path
from the top-left corner to the bottom-right corner which
minimizes the sum of all numbers along its path.

You can only move:
1. Right
2. Down

Example:
Input:
grid = {
    {1,3,1},
    {1,5,1},
    {4,2,1}
}

Output:
7

Explanation:
Minimum path = 1 → 3 → 1 → 1 → 1
Sum = 7
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minPathSum(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();

    // Last row
    for (int j = m - 2; j >= 0; j--)
    {
        grid[n - 1][j] += grid[n - 1][j + 1];
    }

    // Last column
    for (int i = n - 2; i >= 0; i--)
    {
        grid[i][m - 1] += grid[i + 1][m - 1];
    }

    // Fill remaining cells
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = m - 2; j >= 0; j--)
        {
            grid[i][j] += min(grid[i + 1][j], grid[i][j + 1]);
        }
    }

    return grid[0][0];
}

int main()
{
    vector<vector<int>> grid =
    {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    cout << "Minimum Path Sum: " << minPathSum(grid);

    return 0;
}