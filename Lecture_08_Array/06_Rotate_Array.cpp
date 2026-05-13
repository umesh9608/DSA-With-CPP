// rotate an array
#include <iostream>
using namespace std;

int main()
{
  // initialize array
  int arr[8] = {2, 3, 7, 1, -11, 8, 13, 12};

  // store last element
  int num = arr[7];

  // shift all elements one step to the right
  for (int i = 6; i >= 0; i--)
  {
    arr[i + 1] = arr[i];
  }

  // put last element at first position
  arr[0] = num;

  // print updated array
  for (int i = 0; i < 8; i++)
    cout << arr[i] << " ";

  return 0;
}