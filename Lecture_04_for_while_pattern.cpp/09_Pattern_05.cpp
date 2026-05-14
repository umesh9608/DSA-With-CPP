/*

* 
* *
* * *
* * * *
* * * * *

*/

#include<iostream>
using namespace std;
int main(){
    // int n=4;
    for(int row = 0; row < 4; row++){
        for(int col = 0; col <= row; col++){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}

//--------type 1
for (int i = 0; i <= 5; i++){
    for (int j = 0; j <= i; j++){
        cout << "*";
    }
    cout << endl;
}



//---type 2
for (int i = 1; i <= 6; i++){
    for (int j = 1; j <= i; j++){
        cout << "*";
    }
    cout << endl;
}

//----type 3
int i = 1;
while(i <= 6){
    int j = 1;
    while(j <= i){
        cout << "*";
        j++;
    }
    cout << endl;
    i++;
}

//----type ---4
int i = 1;
do{
    int j = 1;
    do{
        cout << "*";
        j++;
    }while(j <= i);

    cout << endl;
    i++;
}while(i <= 6);

//-----type 5
string s = "";

for(int i = 1; i <= 6; i++){
    s += "*";
    cout << s << endl;
}

//--type 6
void print(int n){
    if(n == 0) return;

    print(n-1);

    for(int i = 0; i < n; i++){
        cout << "*";
    }
    cout << endl;
}

int main(){
    print(6);
}