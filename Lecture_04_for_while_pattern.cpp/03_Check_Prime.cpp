// write a program to check prime number
/*
Prime number divided by 1 & itself *
let check for 15
   we can check 2 to 14 if any number form 2 to 14 can divide 15 then t is not prime
   15%2==1
   15%3==0(not prime) loop break*/

#include <iostream>
using namespace std;
int main()
{
    int num;
    cout << "Enter number:";
    cin >> num;
    // for (int n = 2; n <= num - 1; n++)
    // {
    //     if (num % n == 0)
    //     { // This is the missing piece
    //         cout << "Not Prime";
    //         break; // Exit immediately so it doesn't print "Prime"
    //     }
    // }

    // cout << "Prime Number";

    // ------put some edge case like 1 is not prime
    if (num < 2)
    {
        cout << "Not Prime";
        return 0; // Program ko yahi khatam karne ke liye
    }

    // Yahan "n <= num / 2" use karna behtar hai
    for (int n = 2; n <= num - 1; n++)
    {
        if (num % n == 0)
        {
            cout << "Not a prime";
            return 0;
        }
    }

    cout << "Prime";
    return 0;
}