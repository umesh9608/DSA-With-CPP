/*
DISTANCE OF NEAREST CELL HAVING 1

Given a binary grid of size n * m, find the distance of the
nearest cell having value 1 for each cell.

Distance formula:
|i1 - i2| + |j1 - j2|

where:
(i1, j1) = current cell
(i2, j2) = nearest cell having value 1

There is at least one 1 in the grid.

Example:
Input:
grid = {
    {0,1,1,0},
    {1,1,0,0},
    {0,0,1,1}
}

Output:
{
    {1,0,0,1},
    {0,0,1,1},
    {1,1,0,0}
}
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> nearest(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    // Push all cells having 1 into queue
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && dist[nx][ny] == -1)
            {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return dist;
}

int main()
{
    vector<vector<int>> grid = {
        {0,1,1,0},
        {1,1,0,0},
        {0,0,1,1}
    };

    vector<vector<int>> ans = nearest(grid);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}