//Decimal to binary 
#include<iostream>
using namespace std;

int main(){
    int sum = 0;
    int num;
    cout<<"Enter no: ";
    cin >> num;

    int mul = 1;

    while (num > 0)
    {
        int rem = num % 2;      // binary digit
        sum = sum + (rem * mul);
        num = num / 2;
        mul = mul * 10;
    }

    cout << "Binary: " << sum;

    return 0;
}
//binary to decimal
#include<iostream>
using namespace std;

int main(){
    int sum = 0;
    int num;
    cout<<"Enter binary no: ";
    cin >> num;

    int mul = 1;

    while (num > 0)
    {
        int rem = num % 10;     // binary digit (0 or 1)
        sum = sum + (rem * mul);
        num = num / 10;
        mul = mul * 2;
    }

    cout << "Decimal: " << sum;

    return 0;
}