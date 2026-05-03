//union of array
#include<iostream>
using namespace std;

int main(){
  int arr1[]={2,2,3,4,5};
  int arr2[]={11,2,3,4};

  int n=5, m=4;

  // print arr1 unique
  for(int i=0; i<n; i++){
    bool found = false;

    for(int j=0; j<i; j++){
      if(arr1[i] == arr1[j]){
        found = true;
        break;
      }
    }

    if(!found){
      cout << arr1[i] << " ";
    }
  }

  // check arr2 and print if not in arr1
  for(int i=0; i<m; i++){
    bool found = false;

    for(int j=0; j<n; j++){
      if(arr2[i] == arr1[j]){
        found = true;
        break;
      }
    }

    if(!found){
      cout << arr2[i] << " ";
    }
  }

  return 0;
}