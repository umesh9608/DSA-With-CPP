/*
Question:
FIND THE SUM OF LAST N NODES OF THE LINKED LIST

Given a singly linked list of size M, your task is to complete the
function sumOfLastN_Nodes(), which should return the sum of the last
N nodes of the linked list.

Input:
The function takes two arguments:
1. Reference pointer to the head of the linked list
2. Integer N

There will be T test cases and for each test case the function
will be called separately.
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

int sumOfLastN_Nodes(Node *head, int N){

    Node *fast = head;
    Node *slow = head;

    // Move fast pointer N steps ahead
    for(int i=0; i<N; i++){
        fast = fast->next;
    }

    // Move both pointers
    while(fast != NULL){
        fast = fast->next;
        slow = slow->next;
    }

    // Sum last N nodes
    int sum = 0;
    while(slow != NULL){
        sum += slow->data;
        slow = slow->next;
    }

    return sum;
}

int main(){

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    int N = 3;

    cout << "Sum = " << sumOfLastN_Nodes(head, N);

    return 0;
}