/*
ROTTEN ORANGES

Given a grid of dimension n x m where each cell can have values:
0 -> Empty cell
1 -> Fresh orange
2 -> Rotten orange

A rotten orange at position [i, j] can rot fresh oranges at:
[i-1, j], [i+1, j], [i, j-1], [i, j+1]
in 1 unit of time.

Find minimum time required to rot all oranges.
If impossible, return -1.

Example:
Input:
grid = {
    {0,1,2},
    {0,1,2},
    {2,1,1}
}

Output:
1
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool check(int i, int j, int row, int col)
{
    return (i >= 0 && i < row && j >= 0 && j < col);
}

int orangeRotting(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();

    int goodOrange = 0;

    queue<pair<pair<int, int>, int>> q;

    // Count fresh oranges + push rotten oranges
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
                goodOrange++;
            else if (grid[i][j] == 2)
                q.push({{i, j}, 0});
        }
    }

    int timer = 0;

    while (!q.empty())
    {
        int i = q.front().first.first;
        int j = q.front().first.second;
        timer = q.front().second;
        q.pop();

        // Up
        if (check(i - 1, j, n, m) && grid[i - 1][j] == 1)
        {
            grid[i - 1][j] = 2;
            goodOrange--;
            q.push({{i - 1, j}, timer + 1});
        }

        // Down
        if (check(i + 1, j, n, m) && grid[i + 1][j] == 1)
        {
            grid[i + 1][j] = 2;
            goodOrange--;
            q.push({{i + 1, j}, timer + 1});
        }

        // Left
        if (check(i, j - 1, n, m) && grid[i][j - 1] == 1)
        {
            grid[i][j - 1] = 2;
            goodOrange--;
            q.push({{i, j - 1}, timer + 1});
        }

        // Right
        if (check(i, j + 1, n, m) && grid[i][j + 1] == 1)
        {
            grid[i][j + 1] = 2;
            goodOrange--;
            q.push({{i, j + 1}, timer + 1});
        }
    }

    if (goodOrange > 0)
        return -1;
    else
        return timer;
}

int main()
{
    vector<vector<int>> grid = {
        {0, 1, 2},
        {0, 1, 2},
        {2, 1, 1}
    };

    cout << orangeRotting(grid);

    return 0;
}