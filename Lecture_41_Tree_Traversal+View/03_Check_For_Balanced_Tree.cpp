#include<iostream>
#include<cmath>
using namespace std;

/* CHECK FOR BALANCED TREE

Given a Binary Tree, check whether it is
height balanced or not.

A tree is balanced if the difference between
the height of left subtree and right subtree
is not more than 1 for every node.

Balanced Tree:

          1
         / \
       10   39
      /
     5

Unbalanced Tree:

          1
         /
       10
      /
     5

Output:
True / False
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

    int Height(Node *root, bool &ans)
    {
        if(!root)
            return 0;

        int left = Height(root->left, ans);
        int right = Height(root->right, ans);

        if(abs(left-right) > 1)
            ans = false;

        return 1 + max(left,right);
    }

    bool isBalanced(Node *root)
    {
        bool ans = true;

        Height(root, ans);

        return ans;
    }
};

int main()
{
    // Create tree
    //
    //        1
    //       / \
    //      10 39
    //     /
    //    5

    Node* root = new Node(1);

    root->left = new Node(10);
    root->right = new Node(39);
    root->left->left = new Node(5);

    Solution obj;

    if(obj.isBalanced(root))
        cout<<"Tree is Balanced";
    else
        cout<<"Tree is Not Balanced";

    return 0;
}