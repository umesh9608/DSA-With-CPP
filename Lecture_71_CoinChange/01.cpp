/*
COIN CHANGE II (Recursion)

You are given an integer array coins representing coins of different
denominations and an integer amount.

Return the number of combinations that make up that amount.

You may use each coin an unlimited number of times.

Example:
Input:
coins = {1, 2, 5}
amount = 5

Output:
4

Explanation:
The combinations are:
1+1+1+1+1
1+1+1+2
1+2+2
5
*/

#include <iostream>
#include <vector>
using namespace std;

// Recursive function
int find(int index, int amount, vector<int>& coins)
{
    if (amount == 0)
        return 1;

    if (index < 0)
        return 0;

    if (coins[index] > amount)
        return find(index - 1, amount, coins);

    // Include current coin + Exclude current coin
    return find(index, amount - coins[index], coins)
         + find(index - 1, amount, coins);
}

int change(int amount, vector<int>& coins)
{
    int n = coins.size();
    return find(n - 1, amount, coins);
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 5;

    cout << "Number of Ways: " << change(amount, coins);

    return 0;
}