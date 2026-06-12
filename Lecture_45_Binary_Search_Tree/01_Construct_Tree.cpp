/* 
CONSTRUCT BINARY TREE FROM INORDER & PREORDER
Given two arrays: Inorder and Preorder traversal of a Binary Tree.
The tree can contain duplicate values.
Construct the tree and print its Postorder traversal.

Example 1:
Input:
4
1 6 8 7
1 6 7 8

Output:
8 7 6 1

Explanation:
      1
     / \
    6   7
         \
          8
Postorder: Left -> Right -> Root
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
    // Find the index of element in inorder array in range [start, end]
    int Find(int in[], int num, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (in[i] == num)
                return i;
        }
        return -1; // Should not reach here if input is valid
    }

    // Recursive function to build tree
    Node* Tree(int in[], int pre[], int start, int end, int& index) {
        if (start > end)
            return NULL;

        // Take current node from preorder
        Node* root = new Node(pre[index]);
        index++;  // Move to next element in preorder

        // If leaf node
        if (start == end)
            return root;

        // Find position of root in inorder
        int i = Find(in, root->data, start, end);

        // Recur for left and right subtrees
        root->left = Tree(in, pre, start, i - 1, index);
        root->right = Tree(in, pre, i + 1, end, index);

        return root;
    }

    // Main function to build tree
    Node* buildTree(int in[], int pre[], int n) {
        int index = 0;
        return Tree(in, pre, 0, n - 1, index);
    }

    // Postorder traversal to print the result
    void postOrder(Node* root) {
        if (root == NULL)
            return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
};

// Driver Code
int main() {
    int n;
    cout<<"enter n:";
    cin >> n;
    
    int inorder[n];
    int preorder[n];
    
    for(int i = 0; i < n; i++) cin >> inorder[i];
    for(int i = 0; i < n; i++) cin >> preorder[i];
    
    Solution sol;
    Node* root = sol.buildTree(inorder, preorder, n);
    
    sol.postOrder(root);
    cout << endl;
    
    // TODO: Add memory deallocation if needed for large trees
    return 0;
}