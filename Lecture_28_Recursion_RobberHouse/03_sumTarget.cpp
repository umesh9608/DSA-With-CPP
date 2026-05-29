#include<iostream>
using namespace std;

/*
Check that the target sum is possible or not.

If possible return 1
If not possible return 0

Example:
Input:
arr[] = {2,5,1,6,7}
target = 20

Output:
1

Explanation:
Subset {2,5,6,7} gives sum = 20
*/

void sumPossible(int arr[], int size, int index, int sum, int target, int &ans){

  if(index == size){

    if(sum == target){
      ans = 1;
    }

    return;
  }

  // Exclude current element
  sumPossible(arr, size, index + 1, sum, target, ans);

  // Include current element
  sumPossible(arr, size, index + 1, sum + arr[index], target, ans);
}

int main(){

  int arr[] = {2,5,1,6,7};

  int size = 5;

  int target = 20;

  int ans = 0;

  sumPossible(arr, size, 0, 0, target, ans);

  cout << ans;

  return 0;
}