// decimal to binary exe 5 to 101
#include<iostream>
using namespace std;

int main(){
    int num;
    cout<<"Enter any no: ";
    cin>>num;

    // edge case: agar number 0 hai to direct 0 print karo
    if(num == 0){
        cout << 0;
        return 0;
    }

    int product = 1; // binary place value (1, 10, 100, ...)
    int sum = 0;     // final binary number store karega

    // jab tak number 0 se bada hai tab tak loop chalega
    while (num > 0)
    {
        int digit = num % 2; // remainder nikalo (0 ya 1)
        
        // binary number build kar rahe hain
        sum = sum + (digit * product);

        num = num / 2;       // number ko 2 se divide karo
        product = product * 10; // next place value (1 → 10 → 100)
    }

    cout << "Binary: " << sum; // final result print

    return 0;
}