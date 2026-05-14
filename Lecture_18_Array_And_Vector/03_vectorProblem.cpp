// Create a vector and insert 10 elements

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

    vector<int> v;

    // insert 10 elements
    for(int i = 1; i <= 10; i++) {

        v.push_back(i);
    }

    // print vector
    for(int i = 0; i < v.size(); i++) {

        cout << v[i] << " ";
    }

    cout << endl;

    // descending sort
    sort(v.begin(), v.end(), greater<int>());

    // print after sorting
    for(int i = 0; i < v.size(); i++) {

        cout << v[i] << " ";
    }

    cout << endl;

    // capacity and size
    cout << "Capacity = " << v.capacity() << endl;

    cout << "Size = " << v.size() << endl;

    // remove last element
    v.pop_back();

    // print after pop
    for(int i = 0; i < v.size(); i++) {

        cout << v[i] << " ";
    }

    return 0;
}