/*
Question:
A frog jumps either 1, 2, or 3 steps to reach the top.
Find the total number of ways the frog can reach the top.
Since the answer can be very large, return the answer modulo 1000000007.
*/

#include<iostream>
using namespace std;

int MOD = 1000000007;

// Function to count total ways
int frogJump(int n)
{
    // Base Case
    if(n == 0)
        return 1;

    // Invalid Case
    if(n < 0)
        return 0;

    // Recursive Calls
    return (
        frogJump(n - 1) +
        frogJump(n - 2) +
        frogJump(n - 3)
    ) % MOD;
}

int main()
{
    int n;

    cout << "Enter number of steps: ";
    cin >> n;

    cout << "Total Ways: " << frogJump(n);

    return 0;
}