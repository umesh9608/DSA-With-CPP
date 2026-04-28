//use while loop 
#include<iostream>
using namespace std;
int main(){
    int num = 1234;
int sum = 0;

while(num > 0){
    // sum += num % 10;
    sum =sum + num%10;
    num /= 10;
}
cout << sum;
}