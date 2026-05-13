/*
2 3 4 5 6
3 4 5 6 
4 5 6
5 6
6
*/

#include<iostream>
using namespace std;
int main(){
  int arr[5]={2,3,4,5,6};
for(int i=0; i<5; i++){
  for(int j=i; j<5; j++){
    cout<<arr[j]<<" ";
  }
  cout<<endl;
}

return 0;

}