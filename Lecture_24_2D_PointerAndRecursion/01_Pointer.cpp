//learn pointer
#include<iostream>
using namespace std;
int main(){
  int m;
  cout<<"Enter size of array: ";
  cin>>m;
  int *p=new int[m];//p ek pointer hai jo poit kr rha hai ke array ko
  for(int i=0; i<m; i++)
  p[i] =i*2;

  for(int i=0; i<m; i++)
  cout<<p[i]<<" ";
  return 0;
}