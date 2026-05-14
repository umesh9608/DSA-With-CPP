// Count number of 0's in a sorted matrix

#include<iostream>
#include<vector>
using namespace std;

int main() {

    vector<vector<int>> A = {
        {0,0,0,1},
        {0,0,1,1},
        {0,1,1,1},
        {1,1,1,1}
    };

    int count = 0;

    int row = A.size();
    int col = A[0].size();

    int i = 0;
    int j = col - 1;

    while(i < row && j >= 0) {

        // agar 1 mila
        if(A[i][j] == 1) {

            j--;
        }

        // agar 0 mila
        else {

            count = count + (j + 1);

            i++;
        }
    }

    cout << "Total zeros = " << count;

    return 0;
}