/*
Question:
Find two numbers in an array whose sum is equal to 40.

Example:
Input:
arr[] = {10, 20, 30, 5, 15}
sum = 40

Output:
10 30

Explanation:
10 + 30 = 40
*/

#include<iostream>
using namespace std;

int main(){

    int arr[] = {10, 20, 30, 5, 15};

    int n = 5;

    int sum = 40;

    bool found = false;

    // check every pair
    for(int i = 0; i < n - 1; i++){

        for(int j = i + 1; j < n; j++){

            // check sum
            if(arr[i] + arr[j] == sum){

                cout << arr[i] << " " << arr[j] << endl;

                found = true;
            }
        }
    }

    // if no pair found
    if(found == false){
        cout << "No pair found";
    }

    return 0;
}