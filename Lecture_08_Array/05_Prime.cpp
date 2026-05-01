//In array tocheck prime no
#include<iostream>
using namespace std;

void Prime(int num){
  if(num<2)
  return;

  for(int i=2; i<=num-1; i++){
    if(num % i == 0){
      return;
    }
  }
  cout<<num<<" ";
  return;
}

int main(){
int arr[5]={1,2,3,4,5};
for(int i=0; i<=4; i++){
  Prime(arr[i]);
}
}