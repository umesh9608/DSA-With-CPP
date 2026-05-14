/*
1
1 2
1 2 3
1 2 3 4
*/

#include<iostream>
using namespace std;
int main(){
    for(int row = 0; row < 4; row++){
        for(int col = 0; col <= row; col++){
            cout<<col+1 , cout<<" ";
        }
        cout<<endl;
    }
}