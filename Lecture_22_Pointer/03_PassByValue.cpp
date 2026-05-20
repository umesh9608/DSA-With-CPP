#include<iostream>
using namespace std;

/*
=================================================
1. CALL BY VALUE
=================================================

👉 Function ko variables ki COPY milti hai

- Original value change nahi hoti
- Sirf copied values change hoti hain
*/

void fun1(int c, int d){

    c = c * 2;
    d = d * 2;

    cout << "Inside Function : ";
    cout << c << " " << d << endl;
}






/*
=================================================
2. CALL BY ADDRESS
=================================================

👉 Function ko variable ka ADDRESS milta hai

- Pointer use hota hai
- Original value change ho jati hai
*/

void fun2(int *c, int *d){

    *c = (*c) * 2;
    *d = (*d) * 2;
}






/*
=================================================
3. CALL BY REFERENCE
=================================================

👉 Function directly original variable ko access karta hai

- Reference variable use hota hai
- Original value change ho jati hai
*/

void fun3(int &c, int &d){

    c = c * 2;
    d = d * 2;
}






int main(){

    // -----------------------------------------
    // CALL BY VALUE
    // -----------------------------------------

    int a = 5;
    int b = 8;

    fun1(a, b);

    cout << "After Call By Value : ";
    cout << a << " " << b << endl;


    cout << endl;



    // -----------------------------------------
    // CALL BY ADDRESS
    // -----------------------------------------

    int x = 5;
    int y = 8;

    fun2(&x, &y);

    cout << "After Call By Address : ";
    cout << x << " " << y << endl;


    cout << endl;



    // -----------------------------------------
    // CALL BY REFERENCE
    // -----------------------------------------

    int p = 5;
    int q = 8;

    fun3(p, q);

    cout << "After Call By Reference : ";
    cout << p << " " << q << endl;


    return 0;
}