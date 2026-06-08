#include<iostream>
using namespace std;

/* HEIGHT OF BINARY TREE

Given a Binary Tree, find its height.

Example:

Input:

        1
       / \
      2   3

Output:
2

Explanation:
Height = Number of nodes in the
longest path from root to leaf.
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

int height(Node* root)
{
    // Empty tree
    if(!root)
        return 0;

    // Height of left subtree
    int leftHeight = height(root->left);

    // Height of right subtree
    int rightHeight = height(root->right);

    // Return maximum height + current node
    return max(leftHeight, rightHeight) + 1;
}

int main()
{
    // Create Tree
    //         1
    //       /   \
    //      2     3

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    cout<<"Height of Binary Tree: ";
    cout<<height(root);

    return 0;
}