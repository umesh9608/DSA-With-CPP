/*
FLOYD WARSHALL ALGORITHM

Given a weighted graph represented as an adjacency matrix,
find the shortest distance between every pair of vertices.

Note:
- -1 means there is no direct edge.
- Replace -1 with INF before processing.
- After the algorithm, convert INF back to -1.

Time Complexity: O(V^3)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void shortest_distance(vector<vector<int>>& matrix)
{
    int n = matrix.size();

    // Replace -1 with INF
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
                matrix[i][j] = 1e9;

            if (i == j)
                matrix[i][j] = 0;
        }
    }

    // Floyd Warshall Algorithm
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = min(matrix[i][j],
                                   matrix[i][k] + matrix[k][j]);
            }
        }
    }

    // Convert INF back to -1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1e9)
                matrix[i][j] = -1;
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {
        {0, 3, -1, 7},
        {-1, 0, 2, -1},
        {-1, -1, 0, 1},
        {6, -1, -1, 0}
    };

    shortest_distance(matrix);

    cout << "Shortest Distance Matrix:\n";

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}