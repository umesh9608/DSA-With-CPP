/*
Question:
Find if there exists a pair in a sorted array
whose sum is equal to a given target.

Example:
Input:
arr[] = {5, 10, 15, 20, 25, 30}
sum = 40

Output:
Pair Found

Explanation:
15 + 25 = 40
*/

#include<iostream>
using namespace std;

int main(){

    // sorted array
    int arr[] = {5, 10, 15, 20, 25, 30};

    // size of array
    int n = 6;

    // target sum
    int sum = 40;

    // two pointers
    int left = 0;
    int right = n - 1;

    bool found = false;

    while(left < right){

        // current pair sum
        int currentSum = arr[left] + arr[right];

        // check sum
        if(currentSum == sum){

            cout << "Pair Found: ";
            cout << arr[left] << " " << arr[right];

            found = true;
            break;
        }

        // if sum is greater
        else if(currentSum > sum){
            right--;
        }

        // if sum is smaller
        else{
            left++;
        }
    }

    // if pair not found
    if(found == false){
        cout << "Pair Not Found";
    }

    return 0;
}