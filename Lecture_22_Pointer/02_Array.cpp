#include<iostream>
using namespace std;
int main(){
  int arr[5]={10,20,30,40,50};
  // cout<<arr<<endl; //0x61fefc show hexa decimal value
  // cout<<*arr <<endl;//10
  // cout<<*(arr+0) <<endl; //10
  // cout<<*(arr+1) <<endl; //20

  int *p;
  p=arr;
  for (int i = 0; i < 5; i++)
  {
    cout<<*p<<" ";//10 20 30 40 50 
    p++;
  }
  

  return 0;
}