//Sorting an array
#include <iostream>
using namespace std;

int main()
{
  int arr[5] = {0, 1, 2, 1, 0};
  int n = 5;

  int count_zero = 0, count_one = 0, count_two = 0;

  // count 0s, 1s, 2s
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == 0)
      count_zero++;
    else if (arr[i] == 1)
      count_one++;
    else
      count_two++;
  }

  // fill array
  for (int i = 0; i < count_zero; i++)
    arr[i] = 0;

  for (int i = count_zero; i < count_zero + count_one; i++)
    arr[i] = 1;

  for (int i = count_zero + count_one; i < n; i++)
    arr[i] = 2;

  // print result
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";

  return 0;
}