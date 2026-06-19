/*
PAIR IN STL

Write a C++ program to demonstrate the use of pair in STL.

Tasks:
1. Create a pair of two integers and store values 10 and 20.
2. Print both values using first and second.
3. Create a nested pair:
      pair<int, pair<int, int>>
4. Store values:
      first = 1
      second.first = 10
      second.second = 20
5. Print all values.

Example Output:
10 20
1
10
20
*/

#include<iostream>
using namespace std;

int main()
{
    pair<int,int> p;
    p.first = 10;
    p.second = 20;

    // p = make_pair(10, 20);

    cout << p.first << " " << p.second << " " << endl;

    pair<int, pair<int,int>> q;
    q.first = 1;
    q.second.first = 10;
    q.second.second = 20;

    cout << q.first << endl;
    cout << q.second.first << endl;
    cout << q.second.second << endl;

    return 0;
}