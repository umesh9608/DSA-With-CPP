/*
Painter's Partition Problem

Dipreet wants to paint his dog's house which has N boards
of different lengths.

The length of each board is given in an array arr[],
where arr[i] represents the length of the i-th board.

There are K painters available, and each painter takes
1 unit of time to paint 1 unit length of board.

The task is to find the minimum time required to paint
all the boards under the following conditions:

1. Every painter paints only contiguous boards.
2. A board can be painted by only one painter.
3. All painters start painting at the same time.

A painter can paint:
{2,3,4} or {1} or nothing
but cannot paint non-contiguous boards like {2,4,5}.

Example:
Input:
arr[] = {5, 10, 30, 20, 15}
N = 5
K = 3

Output:
35

Explanation:
Possible allocation:
Painter 1 -> {5,10}
Painter 2 -> {30}
Painter 3 -> {20,15}

Maximum time = 35
which is the minimum possible answer.
*/

#include<iostream>
using namespace std;

bool isPossible(int arr[], int n, int k, int mid) {

    int painterCount = 1;
    int boardSum = 0;

    for(int i = 0; i < n; i++) {

        // single board greater than mid
        if(arr[i] > mid) {
            return false;
        }

        if(boardSum + arr[i] <= mid) {
            boardSum += arr[i];
        }
        else {
            painterCount++;
            boardSum = arr[i];

            if(painterCount > k) {
                return false;
            }
        }
    }

    return true;
}

int minTime(int arr[], int n, int k) {

    int start = 0;
    int end = 0;

    for(int i = 0; i < n; i++) {
        end += arr[i];
    }

    int ans = -1;

    while(start <= end) {

        int mid = start + (end - start) / 2;

        if(isPossible(arr, n, k, mid)) {
            ans = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    return ans;
}

int main() {

    int arr[] = {5, 10, 30, 20, 15};
    int n = 5;
    int k = 3;

    cout << "Minimum Time = " << minTime(arr, n, k);

    return 0;
}