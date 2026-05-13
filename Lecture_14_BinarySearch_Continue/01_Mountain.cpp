//An Array a mountian if the following poroperties hold: arr.length>=3



// Question:
// Given a mountain array arr, return the index of the peak element.
//
// A mountain array means:
// 1. arr.length >= 3
// 2. Elements first increase then decrease.
//
// Example:
// Input:  [1,3,5,7,6,4,2]
// Output: 3
//
// Explanation:
// arr[3] = 7 is the peak element.
#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {

    int start = 0;
    int end = arr.size() - 1;

    while (start < end) {

        int mid = start + (end - start) / 2;

        // increasing part
        if (arr[mid] < arr[mid + 1]) {
            start = mid + 1;
        }
        // decreasing part
        else {
            end = mid;
        }
    }

    return start;
}

int main() {

    vector<int> arr = {1, 3, 5, 7, 6, 4, 2};

    cout << "Peak Index: " << peakIndexInMountainArray(arr);

    return 0;
}
