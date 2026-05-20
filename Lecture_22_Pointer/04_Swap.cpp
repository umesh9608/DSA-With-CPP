#include<iostream>
using namespace std;
void swap(int &c,int &d){
  int temp=c;
  c=d;
  d=temp;
}

int main(){
  int a=5,b=8;
  swap(a,b);
  cout<<a<<" "<<b;
  return 0;
}