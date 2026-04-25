//given 3 number print maximum
#include<iostream>
using namespace std;
int main(){
    //-----use && op
    // int a=10,b=15,c=20;
    // if(a>= b && a >= c)
    // cout<<a <<" is gratter";
    // else if(b>=a && b>=c)
    // cout<<b << " is gratter";
    // else
    // cout<<c <<" is gratter";

    //----------use or op
    // int a = 3, b = 15;

    // if(a > 5 || b > 10){
    //     cout << "At least one condition is true";
    // }
    // return 0;


    //------not op
     int a = 10;

    if(!(a < 5)){
        cout << "Condition is false, so NOT makes it true";
    }
    return 0;
}
