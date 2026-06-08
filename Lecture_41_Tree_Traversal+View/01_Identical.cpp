#include<iostream>
using namespace std;

/* DETERMINE IF TWO TREES ARE IDENTICAL

Given two binary trees, determine whether
both trees are identical or not.

Two trees are identical if:
1. Both have same structure
2. Corresponding nodes have same values

Example:

Tree 1              Tree 2

       1               1
      / \             / \
     2   3           2   3

Output:
Yes

Explanation:
Both trees have same nodes and structure.
*/

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

bool identical(Node* root1, Node* root2)
{
    // Both trees are empty
    if(root1 == NULL && root2 == NULL)
        return true;

    // One tree empty and one not
    if(root1 == NULL || root2 == NULL)
        return false;

    // Compare current node and subtrees
    return (root1->data == root2->data) &&
           identical(root1->left, root2->left) &&
           identical(root1->right, root2->right);
}

int main()
{
    // Tree 1
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    // Tree 2
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);

    if(identical(root1, root2))
        cout<<"Yes";
    else
        cout<<"No";

    return 0;
}