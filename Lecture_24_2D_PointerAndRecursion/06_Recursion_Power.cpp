#include <iostream>
using namespace std;
int Power(int n)
{
  if (n == 1)
    return 3;
  return 3 * Power(n - 1);
}


int main()
{
  int n;
  cout << "Enter value:";
  cin >> n;
  cout << Power(n);
  return 0;
}