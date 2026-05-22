/*
Question:
Given an array of integers and a key,
check whether the key is present in the array
using recursion.

If the key is found return 1,
otherwise return 0.

Example:
Input:
Array = {2, 4, 6, 8, 10, 12}
Key = 8

Output:
1
*/

#include<iostream>
using namespace std;

// Function to search key using recursion
int search(int *a, int size, int key)
{
    // Base Case
    if(size == 0)
        return 0;

    // Check current element
    if(a[0] == key)
        return 1;

    // Recursive Call
    return search(a + 1, size - 1, key);
}

int main()
{
    int arr[6] = {2, 4, 6, 8, 10, 12};

    int key = 8;

    cout << search(arr, 6, key);

    return 0;
}