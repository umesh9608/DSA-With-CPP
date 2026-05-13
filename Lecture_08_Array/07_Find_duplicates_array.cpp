//find duplicate array arr=2 3 1 2 4
#include<iostream>

using namespace std;
int main(){
    int arr[5]={2,3,1,2,4};
    int n=5;
    int count[n]={0};
    for(int i=0; i<n; i++){
        int index = arr[i];
        count[index]++;
    }
    for(int i = 0; i<n; i++){
        if(count[i]>1){
        cout<<i<<" ";
        }
    }
    return 0;
}