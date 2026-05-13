/*
Question:
Given an N x N binary matrix where each row and column
is sorted in ascending order, find the total number
of zeros present in the matrix.

Example:
Input:
0 0 0 1
0 0 1 1
0 1 1 1
1 1 1 1

Output:
6

Explanation:
Total number of zeros in the matrix = 6
*/

#include<iostream>
using namespace std;

int main(){

    // binary sorted matrix
    int A[4][4] = {
        {0,0,0,1},
        {0,0,1,1},
        {0,1,1,1},
        {1,1,1,1}
    };

    int row = 4;
    int col = 4;

    int count = 0;

    // start from top-right corner
    int i = 0;
    int j = col - 1;

    while(i < row && j >= 0){

        // move left while element is 1
        while(j >= 0 && A[i][j] == 1){
            j--;
        }

        // count zeros
        count += (j + 1);

        // move to next row
        i++;
    }

    // print answer
    cout << "Total zeros = " << count;

    return 0;
}