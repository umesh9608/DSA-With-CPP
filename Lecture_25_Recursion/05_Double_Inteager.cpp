/*
Question:
Given an array of integers,
double the value of each element
using recursion.

Example:
Input:
Array = {2, 4, 6, 8, 10, 12}

Output:
4 8 12 16 20 24
*/

#include<iostream>
using namespace std;

// Function to double each array element
void Double_value(int *a, int size)
{
    // Base Case
    if(size == 0)
        return;

    // Double current element
    a[0] *= 2;

    // Recursive Call
    Double_value(a + 1, size - 1);
}

int main()
{
    int arr[6] = {2, 4, 6, 8, 10, 12};

    // Function Call
    Double_value(arr, 6);

    // Print Updated Array
    for(int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}