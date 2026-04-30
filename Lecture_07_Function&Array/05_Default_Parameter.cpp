#include<iostream>
using namespace std;

// default parameter
int add(int a, int b = 10){
    return a + b;
}

int main(){
    cout << add(5) << endl;     // b = 10 (default use hoga)
    cout << add(5, 20) << endl; // b = 20 (override)

    return 0;
}