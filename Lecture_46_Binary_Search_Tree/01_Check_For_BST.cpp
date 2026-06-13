/*  
CHECK FOR BST

Given the root of a binary tree, check whether it is a Binary Search Tree (BST) or not.

A BST is defined as follows:
1. The left subtree of a node contains only nodes with keys smaller than the node's key.
2. The right subtree of a node contains only nodes with keys greater than the node's key.
3. Both the left and right subtrees must also be Binary Search Trees.

Note: BST cannot contain duplicate nodes.
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

class Solution {
public:
    void Find(Node *root, int &prev_val, bool &ans) {
        if (!root || !ans)
            return;

        Find(root->left, prev_val, ans);

        if (prev_val >= root->data) {
            ans = false;
            return;
        }

        prev_val = root->data;
        Find(root->right, prev_val, ans);
    }

    bool isBST(Node* root) {
        int prev_val = INT_MIN;
        bool ans = true;
        Find(root, prev_val, ans);
        return ans;
    }
};

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    Solution obj;

    if (obj.isBST(root))
        cout << "BST";
    else
        cout << "Not BST";

    return 0;
}