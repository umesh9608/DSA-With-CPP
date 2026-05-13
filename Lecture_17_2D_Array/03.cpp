#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> v;
for(int i=0; i<=10; i++)
    // add elements
    v.push_back(i);
    // print vector
    for(int i = 0; i < v.size(); i++){

        cout << v[i] << " ";
    }

    return 0;
}