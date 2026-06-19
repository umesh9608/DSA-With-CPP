/*
VECTOR OF PAIRS AND SORTING

Write a C++ program to demonstrate vector of pairs.

Tasks:
1. Create a vector of pairs.
2. Insert multiple pairs using push_back().
3. Sort the vector using sort().
   - Sorting is done first by first element.
   - If first elements are equal, sort by second element.
4. Print all sorted pairs.

Example Output:
4 7
4 9
7 8
9 15
10 20
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<pair<int,int>> v;

    v.push_back(make_pair(10,20));
    v.push_back(make_pair(7,8));
    v.push_back(make_pair(4,9));
    v.push_back(make_pair(4,7));
    v.push_back(make_pair(9,15));

    sort(v.begin(), v.end());
    // if i want to print reverse order then
    // sort(v.rbegin(), v.rend());


    for(int i = 0; i < 5; i++)
        cout << v[i].first << " " << v[i].second << endl;

    return 0;
}