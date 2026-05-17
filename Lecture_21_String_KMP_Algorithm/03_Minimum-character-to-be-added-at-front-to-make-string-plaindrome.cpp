// Question:
// Given a string str of length N.
// Find the minimum characters to be added
// at the front to make the string palindrome.
//
// Note:
// A palindrome is a word that reads the same
// forward and backward.
//
// Example:
// Input: AACECAAAA
// Output: 2

#include <iostream>
#include <algorithm>
using namespace std;

bool isPalindrome(string str, int i, int j)
{

  while (i < j)
  {

    if (str[i] != str[j])
    {
      return false;
    }

    i++;
    j--;
  }

  return true;
}

int main()
{

  string str;
  cin >> str;

  int count = 0;

  for (int i = str.size() - 1; i >= 0; i--)
  {

    if (isPalindrome(str, 0, i))
    {
      break;
    }

    count++;
  }

  cout << count;

  return 0;
}