/*
arr = 3 13 12 8 4
print it in reverse and decresement order
4 8 12 13 3
8 12 13 3
12 13 3
13 3
3
*/
#include<iostream>
using namespace std;
int main(){
  int arr[5]={3,13,12,8,4};
  for(int i=0; i<5; i++){
    for(int j=4-i; j>=0; j--){
      cout<<arr[j]<<" ";
    }
    cout<<endl;
  }

  return 0;
}