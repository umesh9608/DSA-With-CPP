/*
Question:
Create a Bank class with:
- balance
- name

Functions:
- SetValue() to deposit money using clerk authentication
- Balance_check() to display balance
- Withdraw() to withdraw money

*/

#include <iostream>
using namespace std;

class Bank
{

private:
    int balance = 0;
    string name;

public:

    // Function to set values
    void SetValue(int amount, string clerk_name, string password)
    {

        // Checking clerk authentication
        if (clerk_name == "rakesh" && password == "123")
        {

            balance += amount;

            cout << "Amount Deposited Successfully" << endl;
        }
        else
        {

            cout << "Invalid Clerk Credentials" << endl;
        }
    }

    // Function to check balance
    void Balance_check()
    {

        cout << "Balance: " << balance << endl;
    }

    // Function to withdraw money
    void Withdraw()
    {

        balance -= 100;

        cout << "Rs 100 Withdrawn" << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main()
{

    // Creating object
    Bank Customer1;

    // Setting values
    Customer1.SetValue(1000, "rakesdh", "123");

    // Checking balance
    Customer1.Balance_check();

    // Withdraw money
    Customer1.Withdraw();

    return 0;
}