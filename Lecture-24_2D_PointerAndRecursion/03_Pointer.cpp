#include<iostream>
using namespace std;

void fun(int *a, int size){
    for(int i = 0; i < size; i++){
        a[i] = i;
    }
}

int main(){
    int m;

    cout << "Enter size: ";
    cin >> m;

    int *p = new int[m];

    fun(p, m);

    // print array
    for(int i = 0; i < m; i++){
        cout << p[i] << " ";
    }

    delete[] p;

    return 0;
}