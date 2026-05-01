#include <iostream>
using namespace std;

int findDuplicate(int arr[], int n)
{
    int ans = 0;

    // Step 1: XOR all array elements
    for(int i = 0; i < n; i++){
        ans ^= arr[i];
    }

    // Step 2: XOR numbers from 1 to n-1
    for(int i = 1; i < n; i++){
        ans ^= i;
    }

    return ans;
}

int main()
{
    int arr[] = {1, 3, 4, 2, 2}; // duplicate = 2
    int n = 5;

    cout << "Duplicate: " << findDuplicate(arr, n);

    return 0;
}