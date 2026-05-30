/*
Question:
INTERSECTION OF TWO SORTED LINKED LISTS

Given two linked lists sorted in increasing order, create a new linked
list representing the intersection of the two linked lists.

The new linked list should be made with its own memory.
The original linked lists should not be changed.

Note:
The linked list elements are not necessarily distinct.

Example:

Input:
L1 = 1 -> 2 -> 3 -> 4 -> 6
L2 = 2 -> 4 -> 6 -> 8

Output:
2 4 6

Explanation:
For the given two linked lists, 2, 4 and 6 are common elements.
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

Node* intersection(Node *head1, Node *head2){

    Node *head = NULL;
    Node *tail = NULL;

    while(head1 != NULL && head2 != NULL){

        if(head1->data == head2->data){

            Node *newNode = new Node(head1->data);

            if(head == NULL){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }

            head1 = head1->next;
            head2 = head2->next;
        }

        else if(head1->data < head2->data){
            head1 = head1->next;
        }

        else{
            head2 = head2->next;
        }
    }

    return head;
}

void print(Node *head){

    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

int main(){

    // L1 = 1 -> 2 -> 3 -> 4 -> 6
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(6);

    // L2 = 2 -> 4 -> 6 -> 8
    Node *head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);
    head2->next->next->next = new Node(8);

    Node *result = intersection(head1, head2);

    cout<<"Intersection List: ";
    print(result);

    return 0;
}