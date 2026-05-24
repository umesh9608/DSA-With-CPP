#include<iostream>
using namespace std;

// Function to merge two sorted parts of array
void merge(int arr[], int l, int m, int r){

  // Create temporary array
  int *ans = new int[r-l+1];

  int first = l;       // Starting index of first half
  int second = m + 1;  // Starting index of second half
  int pos = 0;         // Position for temp array

  // Compare elements of both halves
  while (first <= m && second <= r)
  {
    if(arr[first] <= arr[second])
      ans[pos++] = arr[first++];
    else
      ans[pos++] = arr[second++];
  }

  // Copy remaining elements of first half
  while (first <= m)
  {
    ans[pos++] = arr[first++];
  }

  // Copy remaining elements of second half
  while (second <= r)
  {
    ans[pos++] = arr[second++];
  }

  // Copy sorted elements back to original array
  pos = 0;
  m = l;

  while (m <= r)
    arr[m++] = ans[pos++];

  // Free dynamic memory
  delete []ans;  
}

// Merge Sort function
void mergeShort(int arr[], int l, int r){

  // Base condition
  if(l >= r)
    return;

  // Find middle index
  int mid = l + (r - l) / 2;

  // Sort left half
  mergeShort(arr, l, mid);

  // Sort right half
  mergeShort(arr, mid + 1, r);

  // Merge both halves
  merge(arr, l, mid, r);
}

int main(){

  int arr[] = {5, 2, 8, 1, 3};
  int n = 5;

  // Calling merge sort
  mergeShort(arr, 0, n - 1);

  // Print sorted array
  for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }

  return 0;
}







// #include<iostream>
// using namespace std;

// // Function to merge two sorted parts of array
// void merge(int arr[], int l, int m, int r){

//     // Create temporary array
//     int *ans = new int[r - l + 1];

//     int first = l;      // Starting index of first half
//     int second = m + 1; // Starting index of second half
//     int pos = 0;        // Position for temp array

//     // Compare elements from both halves
//     while(first <= m && second <= r){

//         if(arr[first] <= arr[second]){
//             ans[pos++] = arr[first++];
//         }
//         else{
//             ans[pos++] = arr[second++];
//         }
//     }

//     // Copy remaining elements of first half
//     while(first <= m){
//         ans[pos++] = arr[first++];
//     }

//     // Copy remaining elements of second half
//     while(second <= r){
//         ans[pos++] = arr[second++];
//     }

//     // Copy sorted data back to original array
//     pos = 0;

//     while(l <= r){
//         arr[l++] = ans[pos++];
//     }

//     // Free dynamically allocated memory
//     delete[] ans;
// }

// // Merge Sort function
// void mergeSort(int arr[], int l, int r){

//     // Base condition
//     if(l >= r){
//         return;
//     }

//     // Find middle index
//     int mid = l + (r - l) / 2;

//     // Sort left half
//     mergeSort(arr, l, mid);

//     // Sort right half
//     mergeSort(arr, mid + 1, r);

//     // Merge both sorted halves
//     merge(arr, l, mid, r);
// }

// int main(){

//     int arr[] = {5, 2, 8, 1, 3};
//     int n = 5;

//     // Calling merge sort
//     mergeSort(arr, 0, n - 1);

//     // Print sorted array
//     cout << "Sorted Array: ";

//     for(int i = 0; i < n; i++){
//         cout << arr[i] << " ";
//     }

//     return 0;
// }