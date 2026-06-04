/*
MAXIMUM RECTANGULAR AREA IN A HISTOGRAM

Find the largest rectangular area possible in a given
histogram where the largest rectangle can be made of
a number of contiguous bars.

Assume:
- All bars have same width = 1

Input:
N = 7
arr[] = {6,2,5,4,5,1,6}

Output:
12
*/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int maxArea(vector<int>& arr,int n){

    stack<int> s;

    int max_area=0;
    int i=0;

    while(i<n){

        if(s.empty() || arr[s.top()]<=arr[i]){
            s.push(i);
            i++;
        }
        else{

            int top=s.top();
            s.pop();

            int area;

            if(s.empty()){
                area=arr[top]*i;
            }
            else{
                area=arr[top]*(i-s.top()-1);
            }

            max_area=max(max_area,area);
        }
    }

    while(!s.empty()){

        int top=s.top();
        s.pop();

        int area;

        if(s.empty()){
            area=arr[top]*i;
        }
        else{
            area=arr[top]*(i-s.top()-1);
        }

        max_area=max(max_area,area);
    }

    return max_area;
}

int main(){

    vector<int> arr={6,2,5,4,5,1,6};

    cout<<maxArea(arr,arr.size());

    return 0;
}