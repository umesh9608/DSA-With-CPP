#include<iostream>
using namespace std;
int main(){
  int num=30;
  int *p;
  p=&num;
  *p=20;
cout<<num;
return 0;
}