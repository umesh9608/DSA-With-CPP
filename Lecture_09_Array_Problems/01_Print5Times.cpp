//Print same array 5 times;
// 2 3 13 8 5 in 5 times

#include<iostream>
using namespace std;
int main(){
  int arr[5]={2,3,13,8,5};
  for(int i=0; i<5; i++){  //it line switch
    for(int j=0; j<5; j++){ //it print
      cout<<arr[j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}