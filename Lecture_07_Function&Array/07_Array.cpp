//Array:collection of same datatype. it stored of contigious location
//we use indexing from o because for accessing the address in 1 based indexing can take more time 

//in 1 based indexing :- initial address + (index-1) * size

//in 0 based indexing:- initial address * index*size
#include<iostream>
using namespace std;
int main(){
  int arr[5];
  arr[0]=1, arr[1]=2, arr[2]=3, arr[3]=4, arr[4]=5;
  int sum = 0;
  for(int i=0; i<5; i++){
    sum= sum + arr[i];
  }
  cout<<sum;
  return 0;
}