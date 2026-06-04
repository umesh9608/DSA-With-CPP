/*
REMOVE K DIGITS

Given a non-negative integer S represented as a string,
remove K digits from the number so that the new number
is the smallest possible.

Note:
The given number does not contain any leading zero.

Input:
S = "14811"
K = 3

Output:
11
*/

#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

class Solution{
public:

    string removeKdigits(string S, int K){

        stack<char> st;

        int i=0;
        char num;

        while(i<S.size()){

            num=S[i];

            while(st.size() && st.top()>num && K){
                st.pop();
                K--;
            }

            st.push(num);
            i++;
        }

        while(K && st.size()){
            st.pop();
            K--;
        }

        string ans="";

        while(st.size()){
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        // Remove leading zeros
        int j=0;

        while(j<ans.size() && ans[j]=='0'){
            j++;
        }

        ans=ans.substr(j);

        if(ans.size()==0)
            return "0";

        return ans;
    }
};

int main(){

    Solution obj;

    cout<<obj.removeKdigits("14811",3);

    return 0;
}