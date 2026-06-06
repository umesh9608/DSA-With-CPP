#include<iostream>
#include<vector>
#include<deque>
using namespace std;

/* FIRST NEGATIVE INTEGER IN EVERY WINDOW OF SIZE K

Given an array A[] of size N and a positive integer K,
find the first negative integer for each and every
window (contiguous subarray) of size K.

Example:

Input:
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2

Output:
-8 0 -6 -6

Explanation:

Window {-8,2}  -> -8
Window {2,3}   -> 0
Window {3,-6}  -> -6
Window {-6,10} -> -6
*/

vector<int> firstNegative(int arr[], int n, int k)
{
    deque<int> q;
    vector<int> ans;

    // First window
    for(int i=0; i<k; i++)
    {
        if(arr[i] < 0)
            q.push_back(i);
    }

    // Store answer for first window
    if(q.empty())
        ans.push_back(0);
    else
        ans.push_back(arr[q.front()]);


    // Remaining windows
    for(int i=k; i<n; i++)
    {
        // Remove out of window elements
        while(!q.empty() && q.front() <= i-k)
        {
            q.pop_front();
        }

        // Add current negative element
        if(arr[i] < 0)
        {
            q.push_back(i);
        }

        // Store answer
        if(q.empty())
            ans.push_back(0);
        else
            ans.push_back(arr[q.front()]);
    }

    return ans;
}

int main()
{
    int arr[] = {-8,2,3,-6,10};
    int n = 5;
    int k = 2;

    vector<int> result = firstNegative(arr,n,k);

    cout<<"Output: ";

    for(int x : result)
    {
        cout<<x<<" ";
    }

    return 0;
}