#include<iostream>
using namespace std;

/* CHECK IF LINKED LIST IS PALINDROME

Given a singly linked list of size N containing integers,
the task is to check whether the given linked list is a
palindrome or not.

Example:
Input: 1 -> 2 -> 2 -> 1
Output: true

Input: 1 -> 2 -> 3
Output: false
*/
#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class Solution{
public:

    Node* Reverse(Node* curr)
    {
        Node* prev = nullptr;
        Node* next;

        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(Node *head)
    {
        if(head == nullptr || head->next == nullptr)
            return true;

        Node *first = head, *second = head;
        int count = 0;

        while(first)
        {
            count++;
            first = first->next;
        }

        count = (count + 1)/2 - 1;

        while(count--)
        {
            second = second->next;
        }

        first = second->next;
        second->next = nullptr;

        first = Reverse(first);

        second = head;

        while(first)
        {
            if(first->data != second->data)
                return false;

            first = first->next;
            second = second->next;
        }

        return true;
    }
};

int main()
{
    // 1 -> 2 -> 2 -> 1
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);

    Solution obj;

    if(obj.isPalindrome(head))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}