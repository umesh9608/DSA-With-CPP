/*
MAKE THE ARRAY BEAUTIFUL
*/

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>   // for reverse()

using namespace std;

vector<int> makeBeautiful(vector<int>& arr){

    stack<int> s;

    int i=0;

    while(i < arr.size()){

        if(!s.empty()){

            if((s.top() >= 0 && arr[i] < 0) ||
               (s.top() < 0 && arr[i] >= 0)){
                s.pop();
            }
            else{
                s.push(arr[i]);
            }

        }
        else{
            s.push(arr[i]);
        }

        i++;
    }

    vector<int> ans;

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main(){

    vector<int> arr={4,-2,-1,3};

    vector<int> result=makeBeautiful(arr);

    for(int x:result){
        cout<<x<<" ";
    }

    return 0;
}