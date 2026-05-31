#include<iostream>
using namespace std;

/*
REARRANGE LINKED LIST ODD EVEN POSITION

Given a singly linked list, the task is to rearrange it
in a way that all odd position nodes are together and
all even position nodes are together.

Assume the first element is at position 1,
the second element at position 2, and so on.

Note:
Place all odd positioned nodes first and then all
even positioned nodes while maintaining their relative order.

Example:
Input: 1 -> 2 -> 3 -> 4

Output: 1 -> 3 -> 2 -> 4

Explanation:
Odd position nodes: 1,3
Even position nodes: 2,4

Result: 1 -> 3 -> 2 -> 4
*/

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

Node* rearrange(Node* head)
{
    if(head == NULL || head->next == NULL)
        return head;

    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;

    while(even && even->next)
    {
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;

    return head;
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

    head = rearrange(head);

    cout<<"Rearranged List: ";
    printList(head);

    return 0;
}