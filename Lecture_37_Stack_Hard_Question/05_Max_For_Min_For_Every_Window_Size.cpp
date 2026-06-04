/*
MAXIMUM OF MINIMUM FOR EVERY WINDOW SIZE

Given an integer array, find the maximum of minimum
for every window size.

Note:
Window size varies from 1 to size of array.

Input:
N = 8
arr[] = {10,20,30,40,50,10,70,30}

Output:
70 30 20 10 10 10 10 10
*/

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

vector<int> maxOfMin(vector<int>& arr, int n){

    vector<int> left(n), right(n);
    stack<int> s;

    // Previous Smaller Element
    for(int i=0;i<n;i++){

        while(!s.empty() && arr[s.top()]>=arr[i]){
            s.pop();
        }

        if(s.empty())
            left[i]=-1;
        else
            left[i]=s.top();

        s.push(i);
    }

    while(!s.empty())
        s.pop();

    // Next Smaller Element
    for(int i=n-1;i>=0;i--){

        while(!s.empty() && arr[s.top()]>=arr[i]){
            s.pop();
        }

        if(s.empty())
            right[i]=n;
        else
            right[i]=s.top();

        s.push(i);
    }

    vector<int> ans(n+1,0);

    for(int i=0;i<n;i++){

        int len=right[i]-left[i]-1;

        ans[len]=max(ans[len],arr[i]);
    }

    for(int i=n-1;i>=1;i--){
        ans[i]=max(ans[i],ans[i+1]);
    }

    ans.erase(ans.begin());

    return ans;
}

int main(){

    vector<int> arr={10,20,30,40,50,10,70,30};

    vector<int> result=maxOfMin(arr,arr.size());

    for(int x:result){
        cout<<x<<" ";
    }

    return 0;
}