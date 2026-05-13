//---ek hi naam ke multiple functions, kaam alag-alag.

#include<iostream>
using namespace std;

// function 1
int add(int a, int b){
    return a + b;
}

// function 2
double add(double a, double b){
    return a + b;
}

// function 3
int add(int a, int b, int c){
    return a + b + c;
}

int main(){
    cout << add(2, 3) << endl;        // int version
    cout << add(2.5, 3.5) << endl;    // double version
    cout << add(1, 2, 3) << endl;     // 3 parameter version

    return 0;
}