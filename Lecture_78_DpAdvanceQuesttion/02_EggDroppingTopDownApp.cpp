/*
EGG DROPPING PUZZLE (Top-Down / Memoization)

You are given:
- n eggs
- k floors

Find the minimum number of attempts needed in the worst case
to determine the highest floor from which an egg can be dropped
without breaking.

Example:
Input:
n = 2
k = 10

Output:
4
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Memoization Function
int find(int eggs, int floors, vector<vector<int>>& dp)
{
    // Base Cases
    if (eggs == 1)
        return floors;

    if (floors == 0 || floors == 1)
        return floors;

    if (dp[eggs][floors] != -1)
        return dp[eggs][floors];

    int ans = INT_MAX;

    for (int i = 1; i <= floors; i++)
    {
        int temp = 1 + max(
            find(eggs - 1, i - 1, dp),     // Egg breaks
            find(eggs, floors - i, dp)     // Egg survives
        );

        ans = min(ans, temp);
    }

    return dp[eggs][floors] = ans;
}

int eggDrop(int n, int k)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    return find(n, k, dp);
}

int main()
{
    int eggs, floors;

    cout << "Enter number of eggs: ";
    cin >> eggs;

    cout << "Enter number of floors: ";
    cin >> floors;

    cout << "Minimum Attempts: " << eggDrop(eggs, floors) << endl;

    return 0;
}