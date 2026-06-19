/*
MERGE K SORTED ARRAYS

Given K sorted arrays (2D vector), merge them into one sorted array.

Example:
Input:
A = {
    {1,3,5},
    {2,4,6},
    {0,9,10}
}

Output:
0 1 2 3 4 5 6 9 10

Approach:
Use Min Heap:
1. Insert first element of every row into heap.
2. Extract minimum.
3. Add next element from same row.
4. Repeat until heap becomes empty.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> solve(vector<vector<int>>& A)
{
    vector<int> ans;

    int row = A.size();
    int col = A[0].size();

    // Min Heap
    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
    > minheap;

    // Insert first column
    for (int i = 0; i < row; i++)
    {
        minheap.push(make_pair(A[i][0], make_pair(i, 0)));
    }

    while (!minheap.empty())
    {
        auto p = minheap.top();
        minheap.pop();

        int value = p.first;
        int r = p.second.first;
        int c = p.second.second;

        ans.push_back(value);

        // Push next element of same row
        if (c + 1 < col)
        {
            minheap.push(make_pair(A[r][c + 1], make_pair(r, c + 1)));
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> A = {
        {1, 3, 5},
        {2, 4, 6},
        {0, 9, 10}
    };

    vector<int> result = solve(A);

    for (int x : result)
        cout << x << " ";

    return 0;
}