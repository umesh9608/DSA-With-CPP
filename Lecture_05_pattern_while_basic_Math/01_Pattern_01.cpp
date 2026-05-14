/*
        *                      -->1
      * * *                    -->3
    * * * * *                  -->5
  * * * * * * *                -->7
  
*/

#include<iostream>
using namespace  std;
int main(){
    int row,col,n =4;
    for(row = 1; row <= n; row++){
        for(col = 1; col <= (n-row); col++){
            cout<<" ";
        }
        for(col = 1; col <=(2 * row -1); col++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }

    return 0;
}