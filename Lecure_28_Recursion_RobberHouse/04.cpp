#include<iostream>
using namespace std;

/*
Question:
Print all possible subset sums of the given array using recursion.

Example:
Input:
arr[] = {2,4,1}

Output:
0 1 4 5 2 3 6 7

Explanation:
All possible subset sums are printed.
*/

void sum_possible(int *arr, int size,int index, int sum){

  // Base condition
  if(index == size){

    cout << sum << " ";

    return;
  }

  // Exclude current element
  sum_possible(arr, size, index + 1, sum);

  // Include current element
  sum_possible(arr, size, index + 1, sum + arr[index]);
}

int main(){

  int arr[] = {2,4,1};

  int index = 0, sum = 0;

  sum_possible(arr, 3, index, sum);

  return 0;
}