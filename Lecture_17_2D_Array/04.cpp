#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int x = 10;

    vector<int> v;

    // insert elements
    for (int i = 0; i <= x; i++){
        v.push_back(i);
    }

    // sort in descending order
    // sort(v.rbegin(), v.rend());
    sort(v.rbegin(), v.rend(),greater<int>());

    // print vector
    for (int i = 0; i < v.size(); i++){

        cout << v[i] << " ";
    }

    return 0;
}