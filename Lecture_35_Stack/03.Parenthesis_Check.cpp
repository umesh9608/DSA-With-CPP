/*PARENTHESE CHECKER
Given an expression string X. Examine whether the pairs and the orders of {,},(,),[,] are correnct in texp.
For Example, the function should return 'true' for exp=[()]{}{[()()]()} and 'false' for exp=[(]).
NOTE: The drive code prints "balancded" if function return true, otherwise it prints "not balanced".*/
#include<iostream>
#include<stack>
using namespace std;

bool isBalanced(string exp){

    stack<char> s;

    for(int i=0; i<exp.length(); i++){

        char ch = exp[i];

        // Push opening brackets
        if(ch=='(' || ch=='{' || ch=='['){
            s.push(ch);
        }

        // Check only closing brackets
        else if(ch==')' || ch=='}' || ch==']'){

            if(s.empty()){
                return false;
            }

            if((ch==')' && s.top()=='(') ||
               (ch=='}' && s.top()=='{') ||
               (ch==']' && s.top()=='[')){

                s.pop();
            }
            else{
                return false;
            }
        }
    }

    return s.empty();
}

int main(){

    string exp = "[()]{}{[()()]()}";

    if(isBalanced(exp))
        cout<<"Balanced"<<endl;
    else
        cout<<"Not Balanced"<<endl;

    return 0;
}