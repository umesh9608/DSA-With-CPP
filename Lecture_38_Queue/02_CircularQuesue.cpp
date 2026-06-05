#include<iostream>
using namespace std;

class CircularQueue{
    int *arr;
    int front;
    int rear;
    int size;

public:

    CircularQueue(int size){
        front = rear = -1;
        arr = new int[size];
        this->size = size;
    }

    bool empty(){
        return front == -1 && rear == -1;
    }

    bool full(){
        return front == (rear + 1) % size;
    }

    void push(int data){

        if(full()){
            cout<<"Queue is full\n";
            return;
        }

        if(empty()){
            front = rear = 0;
            arr[rear] = data;
        }
        else{
            rear = (rear + 1) % size;
            arr[rear] = data;
        }
    }

    void pop(){

        if(empty()){
            cout<<"Queue is empty\n";
            return;
        }

        cout<<"Element popped: "<<arr[front]<<endl;

        // only one element exists
        if(front == rear){
            front = rear = -1;
        }
        else{
            front = (front + 1) % size;
        }
    }
};

int main(){

    CircularQueue q(5);

    q.push(10);
    q.push(20);
    q.push(30);

    q.pop();
    q.pop();

    return 0;
}