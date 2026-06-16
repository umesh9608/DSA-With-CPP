/*
DELETE A NODE IN BST

Given a Binary Search Tree and a node value X.
Delete the node with value X from the BST.
If no node with value X exists, do not make any change.

Example:
Input:
        2
       / \
      1   3

X = 12

Output:
1 2 3

Explanation:
There is no node with value 12,
so the tree remains unchanged.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Insert node in BST
Node* insert(Node* root, int val) {
    if (!root)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Find minimum value node
Node* minValue(Node* root) {
    Node* current = root;

    while (current && current->left)
        current = current->left;

    return current;
}

// Delete node from BST
Node* deleteNode(Node* root, int X) {
    if (!root)
        return NULL;

    if (X < root->data) {
        root->left = deleteNode(root->left, X);
    }
    else if (X > root->data) {
        root->right = deleteNode(root->right, X);
    }
    else {
        // Case 1: No child
        if (!root->left && !root->right) {
            delete root;
            return NULL;
        }

        // Case 2: One child (left)
        else if (root->left && !root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: One child (right)
        else if (!root->left && root->right) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 4: Two children
        else {
            Node* temp = minValue(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 3);

    int X = 12; // Node to delete

    root = deleteNode(root, X);

    cout << "BST after deletion: ";
    inorder(root);

    return 0;
}