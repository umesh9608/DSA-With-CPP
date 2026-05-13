/*
Book Allocation Problem

You have N books, and each book contains A[i] number of pages.

There are M students, and the books have to be allocated such that:

1. Each student gets at least one book.
2. Each book is allocated to only one student.
3. Book allocation should be in contiguous order.

Your task is to allocate books in such a way that the maximum
number of pages assigned to a student is minimized.

Return the minimum possible maximum pages.

Note:
If the number of students is greater than the number of books,
return -1.

Example:
Input:
arr[] = {12, 34, 67, 90}
N = 4
M = 2

Output:
113

Explanation:
Possible allocations:
[12, 34] and [67, 90] -> max pages = 157
[12] and [34, 67, 90] -> max pages = 191
[12, 34, 67] and [90] -> max pages = 113

Minimum possible answer = 113
*/

#include<iostream>
using namespace std;

bool isPossible(int arr[], int n, int m, int mid) {

    int studentCount = 1;
    int pageSum = 0;

    for(int i = 0; i < n; i++) {

        // if single book has more pages than mid
        if(arr[i] > mid) {
            return false;
        }

        // add pages
        if(pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        }
        else {
            studentCount++;
            pageSum = arr[i];

            if(studentCount > m) {
                return false;
            }
        }
    }

    return true;
}

int findPages(int arr[], int n, int m) {

    // not possible
    if(m > n) {
        return -1;
    }

    int start = 0;
    int end = 0;

    // calculate sum of pages
    for(int i = 0; i < n; i++) {
        end += arr[i];
    }

    int ans = -1;

    while(start <= end) {

        int mid = start + (end - start) / 2;

        if(isPossible(arr, n, m, mid)) {
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

    int arr[] = {12, 34, 67, 90};
    int n = 4;
    int m = 2;

    int result = findPages(arr, n, m);

    cout << "Minimum pages = " << result;

    return 0;
}