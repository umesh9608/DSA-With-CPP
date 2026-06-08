#include<iostream>
using namespace std;

/* COUNT NON-LEAF NODES IN TREE

Given a Binary Tree of size N,
return the count of all non-leaf nodes.

Example:

         1
       /   \
      2     3
     / \
    4   5

Output:
2

Explanation:
Nodes 1 and 2 are non-leaf nodes.
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

int countNonLeafNodes(Node* root)
{
    // Empty tree
    if(!root)
        return 0;

    // Leaf node
    if(!root->left && !root->right)
        return 0;

    // Current node is non-leaf
    return 1 + countNonLeafNodes(root->left)
             + countNonLeafNodes(root->right);
}

int main()
{
    // Create Tree
    //         1
    //       /   \
    //      2     3
    //     / \
    //    4   5

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout<<"Non-Leaf Nodes Count: ";
    cout<<countNonLeafNodes(root);

    return 0;
}