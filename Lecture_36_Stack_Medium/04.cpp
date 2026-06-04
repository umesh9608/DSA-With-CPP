/*
NEXT GREATER ELEMENT

Given an array arr[] of size N having elements,
find the next greater element for each element.

Input:
N = 4
arr[] = {1,2,3,4}

Output:
2 3 4 -1
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<long long> nextLargestElement(vector<long long> arr, int n){

    stack<int> s;
    vector<long long> ans(n);

    int i=0;

    while(i<n){

        if(s.size()==0){
            s.push(i);
        }
        else{

            if(arr[s.top()] >= arr[i]){
                s.push(i);
            }
            else{

                while(s.size() && arr[s.top()] < arr[i]){
                    ans[s.top()] = arr[i];
                    s.pop();
                }

                s.push(i);
            }
        }

        i++;
    }

    while(s.size()){
        ans[s.top()] = -1;
        s.pop();
    }

    return ans;
}

int main(){

    vector<long long> arr={1,2,3,4};

    vector<long long> result=
    nextLargestElement(arr,arr.size());

    for(int x:result){
        cout<<x<<" ";
    }

    return 0;
}