// Write a program to check whether given year is leap or not.
/* for leap 
leap % 400 == 0 then leap year
year % 4 = 0 & year % 100 != 0 then leap year
otherwise not leap year*/

#include<iostream>
using namespace std;
int main(){
    int year;
    cout<<"Enter any year:";
    cin >> year;
    if(year % 400 == 0)
    cout<<"Leap year";
    else if(year % 4 == 0 && year % 100 != 0)
    cout<<"Leap Year";
    else
    cout<<"Not a leap year";
    return 0;
}