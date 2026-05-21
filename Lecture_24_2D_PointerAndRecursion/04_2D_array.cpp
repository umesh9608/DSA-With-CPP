#include<iostream>
using namespace std;

void fun(int **x, int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            x[i][j] = i + j;
        }
    }
}

int main(){
    int n, m;

    cout << "Enter rows and columns: ";
    cin >> n >> m;

    // row allocation
    int **p = new int*[n];

    // column allocation
    for(int i = 0; i < n; i++){
        p[i] = new int[m];
    }

    fun(p, n, m);

    // print 2D array
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << p[i][j] << " ";
        }
        cout << endl;
    }

    // memory free
    for(int i = 0; i < n; i++){
        delete[] p[i];
    }

    delete[] p;

    return 0;
}