/*
Question:
Given head, the head of a singly linked list, find if the linked list
is circular or not.

A linked list is called circular if it is not NULL terminated and all
nodes are connected in the form of a cycle.

Note:
- An empty linked list is considered circular.
- The linked list does not contain any inner loop.
*/

#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

bool isCircular(Node *head){

    // Empty linked list is circular
    if(head == NULL)
        return true;

    Node *temp = head;

    while(temp->next != NULL && temp->next != head){
        temp = temp->next;
    }

    return (temp->next == head);
}

int main(){

    // Creating nodes
    Node *head = new Node{1,NULL};
    Node *second = new Node{2,NULL};
    Node *third = new Node{3,NULL};
    Node *fourth = new Node{4,NULL};

    // Connecting nodes
    head->next = second;
    second->next = third;
    third->next = fourth;

    // Make circular linked list
    fourth->next = head;

    if(isCircular(head))
        cout<<"Circular Linked List";
    else
        cout<<"Not Circular Linked List";

    return 0;
}