/*
Question:
Given a sorted array of integers and a key,
check whether the key is present in the array
using Recursive Binary Search.

If the key is found return 1,
otherwise return 0.

Example:
Input:
Array = {2, 4, 5, 7, 8, 9, 23, 25, 29, 30}
Key = 25

Output:
1
*/

#include<iostream>
using namespace std;

// Function for Recursive Binary Search
int binarySearch(int *a, int start, int end, int key)
{
    // Base Case
    if(end < start)
        return 0;

    // Find Middle Index
    int mid = start + (end - start) / 2;

    // Check middle element
    if(a[mid] == key)
        return 1;

    // Search in left half
    else if(a[mid] > key)
        return binarySearch(a, start, mid - 1, key);

    // Search in right half
    else
        return binarySearch(a, mid + 1, end, key);
}

int main()
{
    int arr[10] = {2, 4, 5, 7, 8, 9, 23, 25, 29, 30};

    int key = 25;

    cout << binarySearch(arr, 0, 9, key);

    return 0;
}