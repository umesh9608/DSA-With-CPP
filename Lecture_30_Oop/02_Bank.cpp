/*
Question:
Create a Bank class with:
- balance
- name

Functions:
- SetValue() to set customer details
- Balance_check() to display balance
- Withdraw() to withdraw money

*/

#include<iostream>
using namespace std;

class Bank{

private:

    int balance;
    string name;

public:

    // Function to set values
    void SetValue(int amount, string names){

        balance = amount;
        name = names;
    }

    // Function to check balance
    void Balance_check(){

        cout << "Balance: " << balance << endl;
    }

    // Function to withdraw money
    void Withdraw(){

        balance -= 100;

        cout << "Rs 100 Withdrawn" << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main(){

    // Creating object
    Bank Customer1;

    // Setting values
    Customer1.SetValue(1000, "Pridhi");

    // Checking balance
    Customer1.Balance_check();

    // Withdraw money
    Customer1.Withdraw();

    return 0;
}

/*
This can also check problem. Because user or anyone can update the balance easily.

so, we have to make this like whenever we want to pudate balance, we cannot update it directly. we can update it with the permission of bank employee and they can verify it
*/