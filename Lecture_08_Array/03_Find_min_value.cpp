//fint the minimum value in an array
#include<iostream>
using namespace std;

int main(){
  // initialize array
  int arr[6]={4,3,5,7,84,34};

  // assume first element is minimum
  int min = arr[0];

  // loop through array
  for(int i=1; i<6; i++){
    
    // check if current element is smaller
    if(arr[i] < min){
      
      // update minimum value
      min = arr[i];
    }
  }

  // print minimum element
  cout << min;

  return 0;
}