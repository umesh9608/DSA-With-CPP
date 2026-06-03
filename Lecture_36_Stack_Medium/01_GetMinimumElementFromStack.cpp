/*
GET MINIMUM ELEMENT FROM STACK

You are given N elements and your task is to implement a Stack
in which you can get a minimum element in O(1) time.
*/

#include<iostream>
#include<stack>
using namespace std;

class Solution{
    int minEle;
    stack<int> s;

public:

    int getMin(){
        if(s.empty())
            return -1;

        return minEle;
    }

    int pop(){

        if(s.empty())
            return -1;

        int t = s.top();
        s.pop();

        if(t >= minEle)
            return t;

        int ans = minEle;
        minEle = 2*minEle - t;

        return ans;
    }

    void push(int x){

        if(s.empty()){
            minEle = x;
            s.push(x);
        }
        else{
            if(x >= minEle){
                s.push(x);
            }
            else{
                s.push(2*x - minEle);
                minEle = x;
            }
        }
    }
};

int main(){

    Solution st;

    st.push(10);
    st.push(5);
    st.push(15);
    st.push(2);

    cout<<"Minimum: "<<st.getMin()<<endl;

    cout<<"Popped: "<<st.pop()<<endl;

    cout<<"Minimum: "<<st.getMin()<<endl;

    return 0;
}