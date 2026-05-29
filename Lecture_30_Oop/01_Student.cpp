/*
Question:
Create a Student class with data members:
- name
- reg_no
- branch

Create an object and print student details.

*/

#include<iostream>
using namespace std;

class student{

public:

    string name;
    int reg_no;
    string branch;
};

int main(){

    // Creating object
    student std1;

    // Assigning values
    std1.name = "Paridhi";
    std1.reg_no = 131;
    std1.branch = "sce";

    // Printing details
    cout << "Name: " << std1.name << endl;
    cout << "Registration No: " << std1.reg_no << endl;
    cout << "Branch: " << std1.branch << endl;

    return 0;
}