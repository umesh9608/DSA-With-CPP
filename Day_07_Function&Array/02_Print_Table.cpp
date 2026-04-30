//write a program to print table using function
#include<iostream>
using namespace std;

void printTable(int num){
    for(int i = 1; i <= 10; i++){
        cout << num << " * " << i << " = " << num * i << endl;
    }
    return;
}

int main(){
    int n;
    cout << "Enter number : ";
    cin >> n;

    printTable(n);   // user input table
    printTable(12);  // fixed table of 12

    return 0;
}