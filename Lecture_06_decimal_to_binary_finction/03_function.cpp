#include<iostream>
using namespace std;

// function to check odd or even
void checkNumber(int n){
    if(n % 2 == 0){
        cout << "Even Number";
    } else {
        cout << "Odd Number";
    }
}

int main(){
    int num;
    cout << "Enter number: ";
    cin >> num;

    checkNumber(num);  // function call

    return 0;
}