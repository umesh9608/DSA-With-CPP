/*
Question:
Merge two sorted arrays into a single sorted array.

Example:
Input:
arr1[] = {1, 3, 5, 7}
arr2[] = {2, 4, 6, 8}

Output:
1 2 3 4 5 6 7 8
*/

#include<iostream>
using namespace std;

int main(){

    // first sorted array
    int arr1[] = {1, 3, 5, 7};

    // second sorted array
    int arr2[] = {2, 4, 6, 8};

    int n1 = 4;
    int n2 = 4;

    // merged array
    int ans[8];

    // pointers
    int i = 0;
    int j = 0;
    int k = 0;

    // merge arrays
    while(i < n1 && j < n2){

        // if elements are equal
        if(arr1[i] == arr2[j]){

            ans[k] = arr1[i];
            k++;
            i++;
            j++;
        }

        // if arr1 element is greater
        else if(arr1[i] > arr2[j]){

            ans[k] = arr2[j];
            k++;
            j++;
        }

        // if arr2 element is greater
        else{

            ans[k] = arr1[i];
            k++;
            i++;
        }
    }

    // remaining elements of arr1
    while(i < n1){

        ans[k] = arr1[i];
        k++;
        i++;
    }

    // remaining elements of arr2
    while(j < n2){

        ans[k] = arr2[j];
        k++;
        j++;
    }

    // print merged array
    for(int x = 0; x < k; x++){
        cout << ans[x] << " ";
    }

    return 0;
}