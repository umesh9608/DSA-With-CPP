/*
SURROUNDED REGIONS

Given a matrix mat of size N x M where every element is either
'X' or 'O'.

Replace all 'O' that are completely surrounded by 'X'.

An 'O' is considered surrounded if:
top, bottom, left, right are all bounded by 'X'
(directly or through connected regions).

Example:
Input:
X X X X
X O X X
X O O X
X O X X
X X O O

Output:
X X X X
X X X X
X X X X
X X X X
X X O O
*/

#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<char>>& mat, int i, int j, int n, int m)
{
    if (i < 0 || j < 0 || i >= n || j >= m || mat[i][j] != 'O')
        return;

    mat[i][j] = '#'; // Mark safe O

    DFS(mat, i - 1, j, n, m); // Up
    DFS(mat, i + 1, j, n, m); // Down
    DFS(mat, i, j - 1, n, m); // Left
    DFS(mat, i, j + 1, n, m); // Right
}

void solve(vector<vector<char>>& mat)
{
    int n = mat.size();
    int m = mat[0].size();

    // Check first and last column
    for (int i = 0; i < n; i++)
    {
        if (mat[i][0] == 'O')
            DFS(mat, i, 0, n, m);

        if (mat[i][m - 1] == 'O')
            DFS(mat, i, m - 1, n, m);
    }

    // Check first and last row
    for (int j = 0; j < m; j++)
    {
        if (mat[0][j] == 'O')
            DFS(mat, 0, j, n, m);

        if (mat[n - 1][j] == 'O')
            DFS(mat, n - 1, j, n, m);
    }

    // Convert surrounded O -> X and safe # -> O
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'O')
                mat[i][j] = 'X';
            else if (mat[i][j] == '#')
                mat[i][j] = 'O';
        }
    }
}

int main()
{
    vector<vector<char>> mat = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'O'}
    };

    solve(mat);

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    return 0;
}