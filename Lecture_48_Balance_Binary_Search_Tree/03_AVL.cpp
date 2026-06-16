/*
AVL TREE INSERTION (BASIC)

Write a program to insert nodes into a Binary Search Tree.
Each node stores:
1. data
2. height
3. left child
4. right child

Also implement:
- getHeight()
- Right Rotation

Input:
Enter values one by one.
Enter -1 to stop.

Output:
Inorder traversal of BST.
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data, height;
    Node *left, *right;

    Node(int value)
    {
        data = value;
        height = 1;
        left = right = NULL;
    }
};

int getHeight(Node *root)
{
    if (!root)
        return 0;

    return root->height;
}

Node* rotateRight(Node *root)
{
    Node *temp = root->left;
    Node *subTree = temp->right;

    temp->right = root;
    root->left = subTree;

    return temp;
}

Node* insertBST(Node *root, int value)
{
    if (!root)
        return new Node(value);

    if (value < root->data)
        root->left = insertBST(root->left, value);
    else
        root->right = insertBST(root->right, value);

    return root;
}

void inorder(Node *root)
{
    if (!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = NULL;
    int value;

    cout << "Enter values (-1 to stop): ";

    while (true)
    {
        cin >> value;

        if (value == -1)
            break;

        root = insertBST(root, value);
    }

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}