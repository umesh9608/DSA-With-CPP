//Search insert position of k in a sorted array;
#include <iostream>
#include <vector>
using namespace std;

int searchInsertK(vector<int> arr, int n, int target) {
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return start;  // correct insert position
}

int main() {
    vector<int> arr = {1, 3, 5, 6};
    int target = 2;

    cout << "Position: " << searchInsertK(arr, arr.size(), target);

    return 0;
}