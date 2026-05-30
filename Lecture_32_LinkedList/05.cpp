/*
Question:
INTERSECTION POINT IN Y-SHAPED LINKED LISTS

Given two singly linked lists of size N and M,
write a program to get the point where two linked
lists intersect each other.

Example:

Input:

List1 : 1 -> 2 -> 3
                     \
                      6 -> 7 -> 8
                     /
List2 : 4 -> 5

Output:
6

Explanation:
The two linked lists intersect at node having value 6.
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

int intersectionPoint(Node *head1, Node *head2){

    Node *ptr1 = head1;
    Node *ptr2 = head2;

    // Traverse both lists
    while(ptr1 != ptr2){

        if(ptr1 == NULL)
            ptr1 = head2;
        else
            ptr1 = ptr1->next;

        if(ptr2 == NULL)
            ptr2 = head1;
        else
            ptr2 = ptr2->next;
    }

    // Return intersection data
    if(ptr1 != NULL)
        return ptr1->data;

    return -1;
}

int main(){

    // Common part
    Node *common = new Node(6);
    common->next = new Node(7);
    common->next->next = new Node(8);

    // List 1 : 1->2->3->6->7->8
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = common;

    // List 2 : 4->5->6->7->8
    Node *head2 = new Node(4);
    head2->next = new Node(5);
    head2->next->next = common;

    cout<<"Intersection Point: "
        <<intersectionPoint(head1,head2);

    return 0;
}