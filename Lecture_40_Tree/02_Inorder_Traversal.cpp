#include<iostream>
#include<vector>
using namespace std;

/* Inorder Traversal

Given a binary tree, find the inorder traversal of it.

Example:

Input:

        1
       / \
      3   2

Output:
3 1 2

Inorder:
Left -> Root -> Right
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

class Solution{
public:

    void InorderTraversal(Node *root, vector<int>& ans)
    {
        if(!root)
            return;

        InorderTraversal(root->left, ans);
        ans.push_back(root->data);
        InorderTraversal(root->right, ans);
    }

    vector<int> InOrder(Node* root)
    {
        vector<int> ans;

        InorderTraversal(root, ans);

        return ans;
    }
};

int main()
{
    // Creating tree
    //       1
    //      / \
    //     3   2

    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);

    Solution obj;

    vector<int> result = obj.InOrder(root);

    cout<<"Inorder Traversal: ";

    for(int x : result)
    {
        cout<<x<<" ";
    }

    return 0;
}