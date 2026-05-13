/*
Question:
Given a 2D matrix of size 5x4, print all elements
in diagonal order.

Example Input:
1  2  3  4
5  6  7  8
9 10 11 12
13 14 15 16
17 18 19 20

Output:
1
2 5
3 6 9
4 7 10 13
8 11 14 17
12 15 18
16 19
20

Explanation:
Print all diagonals starting from the first row
and then from the last column.
*/

#include<iostream>
#include<vector>
using namespace std;

int main(){

    int arr[5][4];

    // input matrix
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 4; j++)
            cin >> arr[i][j];

    int row = 0, col = 0, i, j;

    // diagonals starting from first row
    while(col < 4){

        i = 0;
        j = col;

        while(j >= 0){

            cout << arr[i][j] << " ";

            i++;
            j--;
        }

        col++;
    }

    row = 1;

    cout << endl;

    // diagonals starting from last column
    while(row < 5){

        i = row;
        j = 3;

        while(i < 5){

            cout << arr[i][j] << " ";

            i++;
            j--;
        }

        row++;
    }

    return 0;
}