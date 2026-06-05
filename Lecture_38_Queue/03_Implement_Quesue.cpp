#include<iostream>
using namespace std;

class QueueNode{
public:
    int data;
    QueueNode* next;

    QueueNode(int x){
        data = x;
        next = NULL;
    }
};

class MyQueue{
public:
    QueueNode* front;
    QueueNode* rear;

    MyQueue(){
        front = rear = NULL;
    }

    // Push element
    void push(int x)
    {
        QueueNode* temp = new QueueNode(x);

        if(!front)
        {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }

    // Pop element
    int pop()
    {
        if(!front)
            return -1;

        int data = front->data;

        QueueNode* temp = front;

        if(front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            front = front->next;
        }

        delete temp;

        return data;
    }

    // Display Queue
    void display()
    {
        if(!front)
        {
            cout<<"Queue is empty"<<endl;
            return;
        }

        QueueNode* temp = front;

        while(temp)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }

        cout<<endl;
    }
};

int main()
{
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout<<"Queue elements: ";
    q.display();

    cout<<"Popped element: "<<q.pop()<<endl;
    cout<<"Popped element: "<<q.pop()<<endl;

    cout<<"Queue after pop: ";
    q.display();

    return 0;
}