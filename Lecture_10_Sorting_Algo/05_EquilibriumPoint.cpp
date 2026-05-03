/*Given an array A of n positive numbers. The task is to find the first Equilibrium Point in an array.
Equilibrium Point in an array is a postition such that the sum of elements before it is equal to the sum of element after it*/

#include <iostream>
using namespace std;

int main()
{
  int n = 5;
  int a[] = {1, 3, 5, 2, 2};

  for (int i = 0; i < n; i++) {
    int sumRight = 0, sumLeft = 0;

    // right sum
    for (int j = i + 1; j < n; j++) {
      sumRight += a[j];
    }

    // left sum
    for (int j = i - 1; j >= 0; j--) {
      sumLeft += a[j];
    }

    if (sumLeft == sumRight) {
      cout << "Equilibrium Index: " << i+1;
      return 0;
    }
  }

  cout << "No Equilibrium Point";
  return 0;
}