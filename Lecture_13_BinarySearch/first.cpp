//"Write a C++ program to implement Binary Search to find an element in a sorted array."
#include <iostream>
using namespace std;

int main()
{
  int arr[] = {2, 4, 6, 8, 10, 12, 14};  // sorted array
  int n = 7;

  int target = 10;  // search value

  int low = 0, high = n - 1, mid;

  while (low <= high)
  {
    mid = (low + high) / 2;

    if (arr[mid] == target)
    {
      cout << "Element found at index: " << mid;
      return 0;
    }
    else if (target > arr[mid])
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }

  cout << "Element not found";
  return 0;
}