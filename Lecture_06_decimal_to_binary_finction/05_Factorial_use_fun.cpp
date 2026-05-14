#include<iostream>
using namespace std;

// function to calculate factorial
int factorial(int n){
    int fact = 1;
    for(int i = 1; i <= n; i++){
        fact = fact * i;
    }
    return fact;
}

int main(){
    int num;
    cout << "Enter number: ";
    cin >> num;

    cout << "Factorial = " << factorial(num);

    return 0;
}