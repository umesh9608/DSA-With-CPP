/*
Aggressive Cows Problem

You are given an array consisting of N integers
which denote the positions of stalls.

You are also given an integer K which represents
the number of aggressive cows.

Your task is to assign stalls to the cows such that
the minimum distance between any two cows is as
large as possible.

Input:
The first line contains two space-separated integers:
N and K

The second line contains N space-separated integers
representing the positions of the stalls.

Example:
Input:
N = 5
K = 3

Stalls = {1, 2, 4, 8, 9}

Output:
3

Explanation:
Place cows at positions:
1, 4, and 8

Minimum distance between cows:
4 - 1 = 3
8 - 4 = 4

Minimum distance = 3
which is the maximum possible answer.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int> &stalls, int n, int k, int mid) {

    int cowCount = 1;
    int lastPos = stalls[0];

    for(int i = 1; i < n; i++) {

        if(stalls[i] - lastPos >= mid) {
            cowCount++;
            lastPos = stalls[i];

            if(cowCount == k) {
                return true;
            }
        }
    }

    return false;
}

int solve(int n, int k, vector<int> &stalls) {

    sort(stalls.begin(), stalls.end());

    int start = 1;
    int end = stalls[n - 1] - stalls[0];

    int ans = -1;

    while(start <= end) {

        int mid = start + (end - start) / 2;

        if(isPossible(stalls, n, k, mid)) {
            ans = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return ans;
}

int main() {

    int n = 5;
    int k = 3;

    vector<int> stalls = {1, 2, 4, 8, 9};

    cout << "Maximum minimum distance = "
         << solve(n, k, stalls);

    return 0;
}