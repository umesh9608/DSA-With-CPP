/*
AVL TREE BALANCING

Functions implemented:
1. updateHeight()
2. rotateLeft()
3. rotateRight()
4. Balance()
5. inorder()
6. preorder()

AVL Tree keeps BST balanced using rotations.
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int data, height;
    Node *left, *right;

    Node(int value) {
        data = value;
        height = 1;
        left = right = NULL;
    }
};

int getHeight(Node* root) {
    if (!root)
        return 0;
    return root->height;
}

void updateHeight(Node* root) {
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    root->height = 1 + max(leftHeight, rightHeight);
}

Node* rotateRight(Node* root) {
    Node* temp = root->left;
    Node* subtree = temp->right;

    temp->right = root;
    root->left = subtree;

    updateHeight(root);
    updateHeight(temp);

    return temp;
}

Node* rotateLeft(Node* root) {
    Node* temp = root->right;
    Node* subtree = temp->left;

    temp->left = root;
    root->right = subtree;

    updateHeight(root);
    updateHeight(temp);

    return temp;
}

Node* Balance(Node* root) {
    if (!root)
        return NULL;

    updateHeight(root);

    int balance = getHeight(root->left) - getHeight(root->right);

    // Left Heavy
    if (balance > 1) {
        if (getHeight(root->left->left) >= getHeight(root->left->right)) {
            root = rotateRight(root); // LL
        } else {
            root->left = rotateLeft(root->left); // LR
            root = rotateRight(root);
        }
    }

    // Right Heavy
    else if (balance < -1) {
        if (getHeight(root->right->right) >= getHeight(root->right->left)) {
            root = rotateLeft(root); // RR
        } else {
            root->right = rotateRight(root->right); // RL
            root = rotateLeft(root);
        }
    }

    return root;
}

Node* insert(Node* root, int value) {
    if (!root)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return Balance(root);
}

void inorder(Node* root) {
    if (!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node* root = NULL;

    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 10); // Causes rotation

    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    return 0;
}