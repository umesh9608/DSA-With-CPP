// Cards ko haath me arrange karte ho na? Waise hi ek-ek element ko uski sahi jagah pe insert karte hain

#include<iostream>
using namespace std;
int main(){
  int arr[5]={5,1,3,2,6};
  int n=5;
  for(int i=0; i<n-1; i++){

    for(int j=i; j>=0; j--){

    if(arr[j]>arr[j+1]){
        int temp = arr[j];
      arr[j] =arr[j+1];
      arr[j+1] = temp;
    }
    else{
      break;
    }
  }
  }    // print sorted array
  for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }

  return 0;
}