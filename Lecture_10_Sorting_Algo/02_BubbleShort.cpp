/*Bubble Short:-Bade numbers ko baar-baar compare karke aage (end) bhejte rehte hain*/

#include<iostream>
using namespace std;
int main(){
  int arr[4]={4,1,3,2};
  int n=4;
  for(int i=0; i<n-1; i++){
   for(int j = 0; j < (n-1)-i; j++){
      if(arr[j]> arr[j+1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1]=temp;
      }
    }
  }
    // print sorted array
  for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }

  return 0;
}