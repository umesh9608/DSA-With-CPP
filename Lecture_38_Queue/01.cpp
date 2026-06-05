#include<iostream>
using namespace std;

class Queue{
    int front;
    int rear;
    int *arr;
    int size;

public:
    Queue(int size){
        front = rear = 0;
        this->size = size;
        arr = new int[size];   // allocate memory
    }

    // push element in queue
    void push(int data){
        // queue is full or not
        if(rear == size){
            cout<<"Queue is full\n";
            return;
        }

        arr[rear] = data;
        rear++;     // move rear
    }

    // pop element from Queue
    void pop(){
        if(front == rear){
            cout<<"Queue is empty\n";
            return;
        }

        front++;
    }

    // queue is empty or not
    bool empty(){
        return front == rear;
    }

    void display(){
        for(int i=front; i<rear; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){

    Queue q(5);

    q.push(5);
    q.push(15);
    q.push(25);
    q.push(53);
    q.push(45);

    q.display();

    q.pop();

    q.display();

    return 0;
}

// Problem in Simple Queue:
//
// After deleting (pop) elements, empty spaces at the front
// cannot be reused because rear only moves forward.
//
// Example:
// Queue size = 5
//
// [5] [10] [15] [20] [25]
//
// Pop 3 elements:
//
// [ ] [ ] [ ] [20] [25]
//
// Empty spaces exist at beginning,
// but rear already reached end of array.
//
// If we push another element:
// q.push(30);
//
// Output:
// Queue is full
//
// This causes memory wastage.
//
// Circular Queue solves this problem by reusing
// empty spaces using:
//
// rear = (rear + 1) % size;
// front = (front + 1) % size;