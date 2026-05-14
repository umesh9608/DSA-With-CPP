#include<iostream>
using namespace std;

/*
Question:
Given a 5x4 matrix, print all diagonals
from top-right to bottom-left.

Example Matrix:

1   2   3   4
5   6   7   8
9   10  11  12
13  14  15  16
17  18  19  20

Expected Output:

4 7 10 13
3 6 9
2 5
1
8 11 14 17
12 15 18
16 19
20
*/

int main() {

    int arr[5][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20}
    };

    int i, j;

    // Upper diagonals
    for (int col = 3; col >= 0; col--) {

        i = 0;
        j = col;

        while (i < 5 && j >= 0) {

            cout << arr[i][j] << " ";

            i++;
            j--;
        }

        cout << endl;
    }

    // Lower diagonals
    for (int row = 1; row < 5; row++) {

        i = row;
        j = 3;

        while (i < 5 && j >= 0) {

            cout << arr[i][j] << " ";

            i++;
            j--;
        }

        cout << endl;
    }

    return 0;
}