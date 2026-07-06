/*
NTH FIBONACCI NUMBER (MEMOIZATION)

Given an integer N, find the Nth Fibonacci number using Dynamic Programming
(Memoization).

The Fibonacci series is:
F(0) = 0
F(1) = 1
F(n) = F(n-1) + F(n-2), for n >= 2

Example:
Input:
N = 6

Output:
8

Explanation:
Fibonacci Series:
0 1 1 2 3 5 8
The 6th Fibonacci number is 8.
*/

#include <iostream>
#include <vector>
using namespace std;

int find(int n, vector<int>& dp)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = find(n - 1, dp) + find(n - 2, dp);

    return dp[n];
}

int nthFibonacci(int n)
{
    vector<int> dp(n + 1, -1);
    return find(n, dp);
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Nth Fibonacci Number = " << nthFibonacci(n);

    return 0;
}