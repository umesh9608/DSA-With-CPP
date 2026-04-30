//print factorial
#include<iostream>
using namespace std;

int factorial(int num){
  int ans = 1;
  for(int i = 1; i <= num; i++){
    ans = ans * i; 
  }
  return ans;
}

int main(){
  int num1;
  cout << "Enter number: ";
  cin >> num1;

  int fact = factorial(num1);
  cout << fact;

  return 0;
}