//find the largest number
#include<iostream>
using namespace std;

int main(){
  // initialize array with 6 elements
  int arr[6]={4,3,5,7,84,34};

  // assume first element is the largest
  int largest=arr[0];

  // loop through remaining elements
  for(int i=1; i<6; i++){
    
    // check if current element is greater than largest
    if(arr[i]>largest){
      
      // update largest value
      largest=arr[i];
    }
  }

  // print the largest element
  cout<<largest;

  return 0;
}