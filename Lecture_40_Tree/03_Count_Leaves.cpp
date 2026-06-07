#include<iostream>
using namespace std;

/* Count Leaves in Binary Tree

Given a Binary Tree of size N,
count the number of leaf nodes.

Leaf Node:
A node with no left child and no right child.

Example:

         1
       /   \
      10    39
     /
    5

Output:
2

Explanation:
Leaf nodes are:
5 and 39
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

int countLeaves(Node* root)
{
    if(!root)
        return 0;

    // leaf node
    if(!root->left && !root->right)
        return 1;

    return countLeaves(root->left) +
           countLeaves(root->right);
}

int main()
{
    // Create Tree
    //         1
    //       /   \
    //      10    39
    //     /
    //    5

    Node* root = new Node(1);

    root->left = new Node(10);
    root->right = new Node(39);

    root->left->left = new Node(5);

    cout<<"Number of leaf nodes: ";
    cout<<countLeaves(root);

    return 0;
}