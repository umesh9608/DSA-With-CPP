#include <iostream>
using namespace std;

/* CIRCULAR TOUR

Suppose there is a circle. There are N petrol pumps on that circle.

You will be given two sets of data:
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.

Find a starting point where the truck can start to get
through the complete circle without exhausting its petrol.

Note:
Assume for 1 litre petrol, the truck can go 1 unit distance.

Example:

Input:
N = 4

Petrol = 4 6 7 4
Distance = 6 5 3 5

Output:
1

Explanation:
Petrol pump pairs:
{4,6}, {6,5}, {7,3}, {4,5}

Truck starts from index 1 (2nd petrol pump)
and completes the circle successfully.
*/

struct petrolPump
{
  int petrol;
  int distance;
};

class Solution
{
public:
  int tour(petrolPump p[], int n)
  {
    int deficit = 0;
    int balance = 0;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
      balance += p[i].petrol - p[i].distance;

      if (balance < 0)
      {
        deficit += balance;
        balance = 0;
        start = i + 1;
      }
    }

    if (balance + deficit >= 0)
      return start;
    else
      return -1;
  }
};

int main()
{
  int n = 4;

  petrolPump p[] = {
      {4, 6},
      {6, 5},
      {7, 3},
      {4, 5}};

  Solution obj;

  cout << "Starting Index: " << obj.tour(p, n);

  return 0;
}