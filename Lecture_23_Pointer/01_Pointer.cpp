#include<iostream>
using namespace std;
void double_value(int *a,int size){ //use hue her a[]/*a :-this is ponter not array
  for(int i=0; i<5; i++)
  a[i]=a[i]*2;// we use here *a=*a*2; a++;
}

int main(){
  int arr[5]={1,2,3,4,5};
  double_value(arr,5);
  for(int i=0; i<5; i++)
  cout<<arr[i]<<" ";
  return 0;
}

