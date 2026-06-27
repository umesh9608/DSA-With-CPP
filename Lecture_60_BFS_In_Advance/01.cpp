/*
MINIMUM STEPS BY KNIGHT

Given a chessboard of size N x N,
find minimum steps required for a Knight to reach target position.

Knight moves in 8 possible directions.

Example:
Input:
N = 6
Knight Position = {4, 5}
Target Position = {1, 1}

Output:
3
*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

bool check(int i, int j, int N)
{
    return (i >= 1 && i <= N && j >= 1 && j <= N);
}

int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int N)
{
    int row[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int col[8] = {1, -1, 1, -1, 2, -2, 2, -2};

    queue<pair<pair<int, int>, int> > q;

    q.push(make_pair(make_pair(knightPos[0], knightPos[1]), 0));

    vector<vector<bool> > visit(N + 1, vector<bool>(N + 1, false));
    visit[knightPos[0]][knightPos[1]] = true;

    while (!q.empty())
    {
        int i = q.front().first.first;
        int j = q.front().first.second;
        int step = q.front().second;
        q.pop();

        if (i == targetPos[0] && j == targetPos[1])
            return step;

        for (int k = 0; k < 8; k++)
        {
            int newRow = i + row[k];
            int newCol = j + col[k];

            if (check(newRow, newCol, N) && !visit[newRow][newCol])
            {
                visit[newRow][newCol] = true;
                q.push(make_pair(make_pair(newRow, newCol), step + 1));
            }
        }
    }

    return -1;
}

int main()
{
    int N = 6;

    vector<int> knightPos;
    knightPos.push_back(4);
    knightPos.push_back(5);

    vector<int> targetPos;
    targetPos.push_back(1);
    targetPos.push_back(1);

    cout << minStepToReachTarget(knightPos, targetPos, N);

    return 0;
}