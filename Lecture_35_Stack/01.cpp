#include<iostream>
using namespace std;

/*
Objective:
Create a Stack using an array and implement basic operations:

1. push()  -> Insert element into stack
2. pop()   -> Remove top element
3. peek()  -> Show top element
4. empty() -> Check whether stack is empty or not

Stack follows LIFO (Last In First Out)
*/

class Stack {
    int top;      // stores index of top element
    int *arr;     // dynamic array for stack storage
    int size;     // maximum size of stack

public:

    // Constructor to initialize stack
    Stack(int s) {
        arr = new int[s];
        top = -1;      // initially stack is empty
        size = s;
    }

    // Function to insert element into stack
    void push(int data) {

        // Check stack overflow condition
        if(top == size - 1) {
            cout << "Stack Overflow\n";
            return;
        }

        // Move top and insert data
        top++;
        arr[top] = data;
    }

    // Function to remove top element
    void pop() {

        // Check stack underflow condition
        if(top == -1) {
            cout << "Stack Underflow\n";
            return;
        }

        // Remove top element
        top--;
    }

    // Function to return top element
    int peek() {

        // If stack is empty
        if(top == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }

        return arr[top];
    }

    // Function to check stack is empty or not
    bool empty() {
        return top == -1;
    }

    // Destructor to free memory
    ~Stack() {
        delete[] arr;
    }
};

int main() {

    // Create stack of size 4
    Stack s(4);

    // Insert elements
    s.push(4);
    s.push(4321);
    s.push(14);

    // Display top element
    cout << "Top element: " << s.peek();

    return 0;
}