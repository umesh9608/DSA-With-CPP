#include<iostream>
#include<cmath>
using namespace std;

/*
Question:
Count ways to express a number as sum of powers.

Given two integers x and n,
find the number of ways to express x
as sum of n-th powers of unique natural numbers.

It is given that:
1 <= n < 20

Example:
Input:
x = 10
n = 2

Output:
1

Explanation:
10 = 1^2 + 3^2
*/

void sum_possible(int n, int num, int power,
                  int total, int &count){

  // If total becomes equal to target
  if(total == num){
    count++;
    return;
  }

  // If total exceeds target
  if(total > num)
    return;

  // Stop when power value becomes greater than number
  if(pow(n, power) > num)
    return;

  // Exclude current number
  sum_possible(n + 1, num, power,
               total, count);

  // Include current number
  sum_possible(n + 1, num, power,
               total + pow(n, power), count);
}

int main(){

  int num = 10;

  int power = 2;

  int count = 0;

  sum_possible(1, num, power, 0, count);

  cout << count;

  return 0;
}