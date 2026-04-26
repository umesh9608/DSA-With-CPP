// find the sum of first n natural number
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter no:";
    cin>>n;
   int sum=0;
   for(int i=0; i<=n; i++){
    sum =sum+i;
   }
   cout<<sum;
   return 0;
}