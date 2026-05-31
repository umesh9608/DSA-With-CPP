#include<iostream>
using namespace std;

// Node class for Doubly Linked List
class Node{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

int main()
{
    int arr[5] = {1,2,3,4,5};

    // Create first node
    Node *head = new Node(arr[0]);

    Node *first = head;

    // Create remaining nodes
    for(int i = 1; i < 5; i++)
    {
        first->next = new Node(arr[i]);
        first->next->prev = first;
        first = first->next;
    }

    // Print Doubly Linked List
    first = head;

    cout << "Doubly Linked List: ";

    while(first)
    {
        cout << first->data << " ";
        first = first->next;
    }

    return 0;
}