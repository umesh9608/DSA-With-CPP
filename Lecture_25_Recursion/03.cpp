/*
Question:
Given an array of integers, print the cumulative sum
(prefix sum) of all elements using recursion.

Example:
Input:
2 4 21 8 9 12

Output:
2 6 27 35 44 56
*/

#include<iostream>
using namespace std;

void print_sum(int *a, int sum, int size)
{
    // Base Case
    if(size == 0)
        return;

    // Add current element
    sum += a[0];

    // Print cumulative sum
    cout << sum << " ";

    // Recursive Call
    print_sum(a + 1, sum, size - 1);
}

int main()
{
    int arr[6] = {2, 4, 21, 8, 9, 12};

    int sum = 0;

    print_sum(arr, sum, 6);

    return 0;
}