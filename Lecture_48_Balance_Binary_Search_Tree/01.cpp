/*
DELETE A NODE IN BST

Given a Binary Search Tree (BST) and a value X.
Delete the node with value X from the BST and return the updated root.

Rules of deletion:
1. If node is a leaf node -> delete directly.
2. If node has one child -> replace node with child.
3. If node has two children ->
   Replace node with inorder successor (minimum value in right subtree),
   then delete that successor.

Example:
Input BST:
        50
       /  \
      30   70
     / \   / \
    20 40 60 80

X = 50

Output BST (Inorder):
20 30 40 60 70 80
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

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

Node* minValue(Node* root) {
    Node* current = root;

    while (current && current->left)
        current = current->left;

    return current;
}

Node* deleteNode(Node* root, int x) {
    if (root == NULL)
        return NULL;

    if (x < root->data)
        root->left = deleteNode(root->left, x);

    else if (x > root->data)
        root->right = deleteNode(root->right, x);

    else {
        // Case 1: Leaf node
        if (!root->left && !root->right) {
            delete root;
            return NULL;
        }

        // Case 2: Only left child
        else if (root->left && !root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Only right child
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

void inorder(Node* root) {
    if (!root) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    int x = 50;
    root = deleteNode(root, x);

    cout << "Inorder after deletion: ";
    inorder(root);

    return 0;
}