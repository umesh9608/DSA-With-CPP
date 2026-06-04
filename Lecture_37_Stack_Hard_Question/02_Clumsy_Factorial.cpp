/*
CLUMSY FACTORIAL

The factorial of a positive integer n is the product of all
positive integers less than or equal to n.

We make a clumsy factorial using integers in decreasing order
by swapping out operations with this fixed order:

*, /, +, -

Input:
n = 10

Output:
12
*/

#include<iostream>
#include<stack>
using namespace std;

class Solution{
public:

    int clumsy(int n){

        stack<int> s;

        s.push(n--);

        int i=0;
        int num;

        while(n){

            if(i==0){ // multiplication
                num=s.top();
                s.pop();
                s.push(num*n);
            }

            else if(i==1){ // division
                num=s.top();
                s.pop();
                s.push(num/n);
            }

            else if(i==2){ // addition
                s.push(n);
            }

            else{ // subtraction
                s.push(-n);
            }

            i=(i+1)%4;
            n--;
        }

        int sum=0;

        while(s.size()){
            sum+=s.top();
            s.pop();
        }

        return sum;
    }
};

int main(){

    Solution obj;

    cout<<obj.clumsy(10);

    return 0;
}