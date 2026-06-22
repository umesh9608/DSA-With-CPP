/*
SMALLEST RANGE IN K LISTS

Given K sorted lists of integers of size N each,
find the smallest range that includes at least
one element from each of the K lists.

Example:
Input:
n = 5, k = 3

arr = {
    {1, 3, 5, 7, 9},
    {0, 2, 4, 6, 8},
    {2, 3, 5, 7, 11}
}

Output:
1 2

Explanation:
Range [1,2] contains:
1 from first list
2 from second list
2 from third list
*/

#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

#define N 5

class Solution
{
public:
    pair<int, int> findSmallestRange(int arr[][N], int n, int k)
    {
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > minheap;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        // Insert first element of each list
        for (int i = 0; i < k; i++)
        {
            minheap.push(make_pair(arr[i][0], make_pair(i, 0)));
            mini = min(mini, arr[i][0]);
            maxi = max(maxi, arr[i][0]);
        }

        int start = mini;
        int end = maxi;

        while (!minheap.empty())
        {
            auto temp = minheap.top();
            minheap.pop();

            mini = temp.first;
            int row = temp.second.first;
            int col = temp.second.second;

            if (maxi - mini < end - start)
            {
                start = mini;
                end = maxi;
            }

            if (col + 1 == n)
                break;

            int nextValue = arr[row][col + 1];
            maxi = max(maxi, nextValue);

            minheap.push(make_pair(nextValue, make_pair(row, col + 1)));
        }

        return {start, end};
    }
};

int main()
{
    int arr[3][N] = {
        {1, 3, 5, 7, 9},
        {0, 2, 4, 6, 8},
        {2, 3, 5, 7, 11}
    };

    Solution obj;
    pair<int, int> ans = obj.findSmallestRange(arr, 5, 3);

    cout << ans.first << " " << ans.second;

    return 0;
}