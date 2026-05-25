#include<iostream>
using namespace std;

/*
Quick Sort is a Divide and Conquer algorithm.
It picks an element as a pivot and partitions
the array around the pivot element.
*/

class Solution{
  public:

  // Function for Quick Sort
  void quickShort(int arr[], int low, int high){

    // Base condition
    if(low >= high)
      return;

    // Find pivot position
    int pos = partition(arr, low, high);

    // Sort left part
    quickShort(arr, low, pos - 1);

    // Sort right part
    quickShort(arr, pos + 1, high);
  }

  // Partition function
  int partition(int arr[], int low, int high){

    int pivot = arr[high]; // Last element as pivot
    int pos = low;

    // Place smaller elements before pivot
    for(int i = low; i < high; i++){

      if(arr[i] <= pivot){
        swap(arr[i], arr[pos]);
        pos++;
      }
    }

    // Place pivot at correct position
    swap(arr[pos], arr[high]);

    return pos;
  }
};

int main(){

  int arr[1000], n;

  cout << "Enter size of array: ";
  cin >> n;

  cout << "Enter array elements: ";

  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  Solution obj;

  // Calling Quick Sort
  obj.quickShort(arr, 0, n - 1);

  cout << "Sorted Array: ";

  for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }

  return 0;
}