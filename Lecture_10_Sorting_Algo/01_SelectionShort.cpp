/*Selection Short:-har baar sabse chhota number dhundo aur usko aage rakh do
*/

#include<iostream>
using namespace std;

int main(){
  int arr[5] = {4,2,5,6,1};
  int n = 5;//array size

  for(int i = 0; i < n-1; i++){
    int index = i;

    for(int j = i+1; j < n; j++){
      if(arr[j] < arr[index]){
        index = j;
      }
    }

    // swap outside inner loop
    int temp = arr[index];
    arr[index] = arr[i];
    arr[i] = temp;
  }

  // print sorted array
  for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }

  return 0;
}