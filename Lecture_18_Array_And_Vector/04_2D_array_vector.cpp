#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Topic: 2D Vector and Sorting

Question:
Create a 2D vector of size 4x3.
Take input from the user and sort each row individually
in ascending order using sort() function.

Example Input:
3 1 2
9 5 7
6 4 8
12 10 11

Expected Output:
1 2 3
5 7 9
4 6 8
10 11 12
*/

int main(){

    // 4 rows and 3 columns
    vector<vector<int>> arr(4, vector<int>(3));

    // input
    for(int i = 0; i < 4; i++) {

        for(int j = 0; j < 3; j++) {

            cin >> arr[i][j];
        }
    }

    // sort each row
    for(int i = 0; i < 4; i++) {

        sort(arr[i].begin(), arr[i].end());
    }

    // print matrix
    for(int i = 0; i < 4; i++) {

        for(int j = 0; j < 3; j++) {

            cout << arr[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}