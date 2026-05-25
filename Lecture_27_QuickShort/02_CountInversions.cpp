#include<iostream>
using namespace std;

/*
Question:
Given an array of integers, find the Inversion Count in the array.

Inversion Count:
For an array, inversion count indicates how far
(or close) the array is from being sorted.

If the array is already sorted, then the inversion count is 0.
If the array is sorted in reverse order, then the inversion count is maximum.

Formally, two elements a[i] and a[j] form an inversion if:
a[i] > a[j] and i < j

Input:
N = 5
arr[] = {2, 4, 1, 3, 5}

Output:
3

Explanation:
The array has three inversions:
(2,1), (4,1), (4,3)
*/

long long merge(long long arr[], int l, int m, int r){

    long long *temp = new long long[r - l + 1];

    int left = l;
    int right = m + 1;
    int pos = 0;

    long long count = 0;

    // Merge two sorted halves
    while(left <= m && right <= r){

        if(arr[left] <= arr[right]){
            temp[pos++] = arr[left++];
        }
        else{
            temp[pos++] = arr[right++];

            // Count inversions
            count += (m - left + 1);
        }
    }

    // Copy remaining elements
    while(left <= m){
        temp[pos++] = arr[left++];
    }

    while(right <= r){
        temp[pos++] = arr[right++];
    }

    // Copy back to original array
    pos = 0;

    while(l <= r){
        arr[l++] = temp[pos++];
    }

    delete[] temp;

    return count;
}

long long mergeSort(long long arr[], int l, int r){

    // Base condition
    if(l >= r)
        return 0;

    int mid = l + (r - l) / 2;

    long long leftCount = mergeSort(arr, l, mid);
    long long rightCount = mergeSort(arr, mid + 1, r);

    long long mergeCount = merge(arr, l, mid, r);

    return leftCount + rightCount + mergeCount;
}

int main(){

    long long arr[] = {2, 4, 1, 3, 5};

    int n = 5;

    cout << "Inversion Count = "
         << mergeSort(arr, 0, n - 1);

    return 0;
}