#include <iostream>
using namespace std;

/*
Question:
Check whether the target sum is possible or not
using the given array elements.

If possible return 1
Otherwise return 0
*/

void sum_possible(int arr[], int size, int index,
                  int target, int sum, int &ans)
{

  // Base condition
  if (index == size)
  {
    if (sum == target)
      ans = 1;

    return;
  }

  // If sum becomes greater than target
  if (sum > target)
    return;

  // Exclude current element
  sum_possible(arr, size, index + 1,
               target, sum, ans);

  // Include current element
  sum_possible(arr, size, index + 1,
               target, sum + arr[index], ans);
}

int main()
{
  int arr[] = {2, 4, 6, 8};

  int size = 4;

  int target = 10;

  int ans = 0;

  sum_possible(arr, size, 0, target, 0, ans);

  cout << ans;

  return 0;
}