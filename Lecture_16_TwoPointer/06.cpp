/*
Question:
Given an array where each element represents the height of a building,
find the maximum water that can be stored between any two buildings.

Example:
Input:
arr[] = {1,8,6,2,5,4,8,3,7}

Output:
49

Explanation:
Water stored between height 8 and 7 with distance 7:
7 * 7 = 49
*/

#include<iostream>
using namespace std;

int main(){

    // height array
    int arr[] = {1,8,6,2,5,4,8,3,7};

    // size of array
    int n = 9;

    // store maximum water
    int maxWater = 0;

    // check every pair
    for(int i = 0; i < n - 1; i++){

        for(int j = i + 1; j < n; j++){

            // minimum height
            int bd = min(arr[i], arr[j]);

            // distance between buildings
            int length = j - i;

            // water stored
            int water = bd * length;

            // update maximum water
            maxWater = max(water, maxWater);
        }
    }

    // print answer
    cout << "Maximum Water = " << maxWater;

    return 0;
}