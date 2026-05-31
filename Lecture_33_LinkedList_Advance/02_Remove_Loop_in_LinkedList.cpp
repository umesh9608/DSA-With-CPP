#include<iostream>
using namespace std;

/* REMOVE LOOP IN LINKED LIST

Given a linked list of N nodes such that it may contain a loop.
A loop here means that the last node of the linked list is connected
to the node at position X (1-based index). If the linked list does not
have any loop, X = 0.

Remove the loop from the linked list if it is present.
*/

// Node class
class Node{
public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void removeLoop(Node* head)
{
    if(head == NULL || !head->next)
        return;

    // Self loop case
    if(head == head->next)
    {
        head->next = NULL;
        return;
    }

    Node* slow = head->next;
    Node* fast = head->next->next;

    // Detect loop
    while(fast && fast->next && fast != slow)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    // No loop
    if(!fast || !fast->next)
        return;

    fast = head;

    // Loop starts from head
    if(fast == slow)
    {
        while(slow->next != fast)
        {
            slow = slow->next;
        }

        slow->next = NULL;
        return;
    }

    // Find node before loop start
    while(fast->next != slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = NULL;
}

void printList(Node* head)
{
    while(head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // Creating loop: 4 -> 2
    head->next->next->next->next = head->next;

    removeLoop(head);

    cout << "Linked List after removing loop: ";
    printList(head);

    return 0;
}