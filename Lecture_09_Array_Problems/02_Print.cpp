// arr=3,13,12,11,8 
/*  3 13 12 11 8
    3 13 12 11
    3 13 12
    3 13
    3

*/

#include<iostream>
using namespace std;
int main(){
  int arr[5]={3,13,12,11,8};
  for(int i=0; i<5; i++){
    for(int j= 0; j<5-i; j++){
      cout<<arr[j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}