#include<iostream>
using namespace std;
int main(){
    int arr[] = {4,2,5,6,1,99,54};
  int n = 7;//array size

  for(int i = 0; i<n-1; i++){

    int index=i;
    for(int j = i; j<n; j++){
      if(arr[j]<arr[index]){
        index=j;
      }
    }

    int temp = arr[index];
    arr[index] = arr[i];
    arr[i]= temp;
  }
   for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }

  return 0;
}