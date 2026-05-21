#include<iostream>
using namespace std;
int main(){
  int arr[5]={1,2,3,4,5};
  cout<<arr<<endl;//0x61fefc
  cout<<&arr<<endl;//0x61fefc
  cout<<&arr[0]<<endl;//0x61fefc
  cout<<&arr[1]<<endl;//0x61ff00 jum 4 byte
  return 0;
}
/*
arr
&arr
&arr[0]   are same show first address*/