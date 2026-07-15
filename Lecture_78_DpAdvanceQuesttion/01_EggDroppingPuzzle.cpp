/*
EGG DROPPING PUZZLE (Recursion)

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

Explanation:
With 2 eggs and 10 floors,
minimum attempts required in the worst case is 4.
*/

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

// Recursive function
int find(int eggs, int floors)
{
    // Base Cases
    if (eggs == 1)
        return floors;

    if (floors == 0 || floors == 1)
        return floors;

    int ans = INT_MAX;

    for (int i = 1; i <= floors; i++)
    {
        int temp = 1 + max(
            find(eggs - 1, i - 1),      // Egg breaks
            find(eggs, floors - i)      // Egg survives
        );

        ans = min(ans, temp);
    }

    return ans;
}

int eggDrop(int n, int k)
{
    return find(n, k);
}

int main()
{
    int eggs, floors;

    cout << "Enter number of eggs: ";
    cin >> eggs;

    cout << "Enter number of floors: ";
    cin >> floors;

    cout << "Minimum Attempts: " << eggDrop(eggs, floors);

    return 0;
}