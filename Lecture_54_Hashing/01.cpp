/*
MAP IN STL

Write a C++ program to demonstrate the use of map.

Tasks:
1. Create a map of integer key-value pairs.
2. Insert elements using indexing operator [].
3. Print all elements using iterator.
4. Print total number of elements using size().

Note:
Map stores keys in sorted order.

Example Output:
2 8
3 84
9 15
10 43
4
*/

#include <map>
#include <iostream>
using namespace std;

int main()
{
    map<int, int> m;

    m[3] = 84;
    m[2] = 8;
    m[9] = 15;
    m[10] = 43;

    for (auto i = m.begin(); i != m.end(); i++)
    {
        cout << i->first << " " << i->second << endl;
    }

    cout << m.size() << endl;

    return 0;
}