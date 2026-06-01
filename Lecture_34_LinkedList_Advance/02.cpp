#include<bits/stdc++.h>
using namespace std;

/* REVERSE LINKED LIST II

Given the head of a singly linked list and two integers
m and n, reverse the nodes of the list from position m
to position n and return the modified linked list.

Note:
- Positions are based on 1-indexing.
- Reverse only the nodes between m and n.

Example:

Input:
1 -> 2 -> 3 -> 4 -> 5
m = 2
n = 4

Output:
1 -> 4 -> 3 -> 2 -> 5

Explanation:
Nodes from position 2 to 4 are reversed.
*/

class Node{
public:
    int data;
    Node* next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution{
public:

    Node* Reverse(Node* head, int n)
    {
        Node* prev = NULL;
        Node* next;

        while(n--)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }

    Node* reverseBetween(Node* head, int m, int n)
    {
        if(head == NULL || m == n)
            return head;

        int count1 = m;

        Node* first = NULL;
        Node* second = head;

        // Reach mth node
        while(--count1)
        {
            first = second;
            second = second->next;
        }

        Node* temp = second;

        // Reach (n+1)th node
        int len = n - m + 1;

        while(len--)
        {
            second = second->next;
        }

        if(!first)
        {
            Node* ans = Reverse(head, n);

            temp->next = second;

            return ans;
        }

        first->next = Reverse(first->next, n-m+1);

        temp->next = second;

        return head;
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
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Solution obj;

    head = obj.reverseBetween(head,2,4);

    print(head);

    return 0;
}