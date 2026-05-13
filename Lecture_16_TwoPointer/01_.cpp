/*
Question:
Given a sorted array, count the number of distinct elements present in the array.

Example:
Input:
a[] = {1,1,2,2,3,4,4}

Output:
4

Explanation:
Distinct elements are:
1 2 3 4
*/

#include<iostream>
using namespace std;

int main(){

    // sorted array
    int a[] = {1,1,2,2,3,4,4};

    // size of array
    int n = 7;

    // store first element
    int note = a[0];

    // first element is always distinct
    int count = 1;

    // loop from second element
    for(int i = 1; i < n; i++){

        // check current element is different or not
        if(note != a[i]){

            // update note
            note = a[i];

            // increase distinct count
            count++;
        }
    }

    // print answer
    cout << "Distinct elements = " << count;

    return 0;
}