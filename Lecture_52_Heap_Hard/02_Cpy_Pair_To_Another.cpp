/*
COPY ONE PAIR TO ANOTHER

Write a C++ program to demonstrate copying one pair into another.

Tasks:
1. Create a pair p using make_pair(10, 20).
2. Create another pair p2.
3. Copy pair p into p2.
4. Print values of p2.

Example Output:
10 20
*/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    pair<int,int> p;
    p = make_pair(10,20);

    pair<int,int> p2;
    p2 = p;

    cout << p2.first << " " << p2.second;

    return 0;
}