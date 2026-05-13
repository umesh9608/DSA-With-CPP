/*Question (Interview Type)

 Find Peak Element

Problem:
Given ek array arr[] of size n, find karo koi bhi ek peak element ka index.

 Peak element = jo apne neighbours se bada ho */
#include <iostream>
using namespace std;

int peakElement(int arr[], int n)
{
  int start = 0;
  int end = n - 1;

  while (start <= end)
  {
    int mid = start + (end - start) / 2;

    // check peak safely
    if ((mid == 0 || arr[mid] > arr[mid - 1]) &&
        (mid == n - 1 || arr[mid] > arr[mid + 1]))
    {
      return mid;
    }
    else if (arr[mid] < arr[mid + 1])
    {
      start = mid + 1; // right side me peak hai
    }
    else
    {
      end = mid - 1; // left side me peak hai
    }
  }

  return -1;
}

int main()
{
  int arr[] = {1, 3, 20, 4, 1, 0};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Peak Index: " << peakElement(arr, n);
  return 0;
}