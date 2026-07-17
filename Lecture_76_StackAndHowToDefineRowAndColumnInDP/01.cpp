/*
SUBSET SUM PROBLEM (Recursion)

Given an array of positive integers arr[] and an integer sum,
determine whether there exists a subset of the given array whose
sum is equal to the given sum.

Example:
Input:
arr = {3, 34, 4, 12, 5, 2}
sum = 9

Output:
Yes

Explanation:
Subset {4, 5} has sum = 9.
*/

#include <iostream>
#include <vector>
using namespace std;

// Recursive function
bool find(int n, int sum, vector<int>& arr)
{
    if (sum == 0)
        return true;

    if (n == 0)
        return false;

    // If current element is greater than required sum
    if (arr[n - 1] > sum)
        return find(n - 1, sum, arr);

    // Include or Exclude current element
    return find(n - 1, sum - arr[n - 1], arr) ||
           find(n - 1, sum, arr);
}

bool isSubsetSum(vector<int>& arr, int sum)
{
    int n = arr.size();
    return find(n, sum, arr);
}

int main()
{
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    if (isSubsetSum(arr, sum))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}