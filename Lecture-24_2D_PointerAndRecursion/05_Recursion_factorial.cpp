#include<iostream>
using namespace std;

int factorial(int n){
    if(n == 1 || n == 0)
        return 1;

    int num = factorial(n - 1);

    num = n * num;

    return num;
}

int main(){
    int n;

    cout << "Enter no: ";
    cin >> n;

    cout << "Factorial = " << factorial(n);

    return 0;
}