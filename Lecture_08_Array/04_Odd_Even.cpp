// find the +ve -ve odd  in an aray
#include <iostream>
using namespace std;
int main()
{
  int arr[5] = {1, 2, -3, 4, 5};
  for (int i = 0; i <= 4; i++)
  {
    if (arr[i] % 2 == 1 || arr[i] % 2 == -1)
    {
      cout << arr[i]<<endl;
    }
    
   
  }
  return 0;
}