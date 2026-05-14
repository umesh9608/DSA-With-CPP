/*Typecasting ka matlab hai:
ek data type ko dusre data type me convert karna*/
#include<iostream>
using namespace std;
int main(){
    // char c='8';
    // cout<<c<<endl; //8

    // char a=65;
    // cout<<a<<endl; //A becaue here we use data type is char so 65 convert in A (becaue 65 is a ASCII value)
    // return 0;


    // int c='A';
    // cout <<c<<endl; //65(convert into binary and then check in ASCII and return the integer value associated with it)

    //-------------
    char c=590;
    cout<<c<<endl; //gives a warning sttatment in character we can store only 2^8 =256 value only
    //Maximum we can store 2^8=256 value . 0 to 255
    return 0;
}