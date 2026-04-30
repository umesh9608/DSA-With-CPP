#include<iostream>
using namespace std;

// function to check prime
bool isPrime(int n){
    if(n <= 1) return false;

    for(int i = 2; i < n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int num;
    cout << "Enter number: ";
    cin >> num;

    if(isPrime(num)){
        cout << "Prime";
    } else {
        cout << "Not Prime";
    }

    return 0;
}