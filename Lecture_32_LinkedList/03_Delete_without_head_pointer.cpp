/*
Question:
DELETE WITHOUT HEAD POINTER

You are given a pointer/reference to the node which is to be deleted
from the linked list of N nodes.

The task is to delete the node.

Note:
- No head reference is given.
- It is guaranteed that the node to be deleted
  is not the tail node in the linked list.
*/

#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

void deleteNode(Node *node){

    // Copy next node data into current node
    node->data = node->next->data;

    // Store next node
    Node *temp = node->next;

    // Skip next node
    node->next = node->next->next;

    // Delete extra node
    delete temp;
}

void print(Node *head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

int main(){

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout<<"Before Delete: ";
    print(head);

    // Delete node having value 20
    deleteNode(head->next);

    cout<<"\nAfter Delete: ";
    print(head);

    return 0;
}