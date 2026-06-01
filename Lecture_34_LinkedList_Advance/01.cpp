/* CLONE A LINKED LIST WITH NEXT AND RANDOM POINTER

You are given a special linked list with N nodes where each node has:
1. A next pointer pointing to the next node.
2. A random (arb) pointer pointing to any node in the list.

You are given M pairs (A, B) representing:
A->arb = B

Construct a copy of the given linked list.

The copied list should:
- Consist of exactly N new nodes.
- Each new node should have the same value as its corresponding original node.
- Both next and random pointers of copied nodes should point only to nodes in the copied list.
- No pointer in the copied list should point to any node of the original list.
*/
#include<bits/stdc++.h>
using namespace std;

/* CLONE A LINKED LIST WITH NEXT AND RANDOM POINTER */

struct Node{
    int data;
    Node *next;
    Node *arb;

    Node(int x)
    {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

class Solution{
public:

    Node* copyList(Node *head)
    {
        if(head == NULL)
            return NULL;

        Node* clone = head;
        Node* temp;

        // Insert cloned nodes
        while(clone)
        {
            temp = new Node(clone->data);

            temp->next = clone->next;
            clone->next = temp;

            clone = temp->next;
        }

        // Set random pointers
        clone = head;

        while(clone)
        {
            if(clone->arb)
                clone->next->arb = clone->arb->next;

            clone = clone->next->next;
        }

        // Separate both lists
        Node* ans = head->next;

        clone = head;
        temp = head->next;

        while(temp && temp->next)
        {
            clone->next = temp->next;
            clone = clone->next;

            temp->next = clone->next;
            temp = temp->next;
        }

        clone->next = NULL;

        return ans;
    }
};

void print(Node* head)
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

    // Random pointers
    head->arb = head->next->next;
    head->next->arb = head;
    head->next->next->arb = head->next;

    Solution obj;

    Node* copy = obj.copyList(head);

    cout<<"Cloned List: ";
    print(copy);

    return 0;
}