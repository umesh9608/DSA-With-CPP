/*
4 3 2 1
4 3 2 1
4 3 2 1
*/

#include<iostream>
using namespace std;
int main(){
    for(int row=0; row<4; row++){
        for(int col=0; col<4; col++){
            cout<<4-col , cout<<" ";
        }
        cout<<endl;
    }

    return 0;
}