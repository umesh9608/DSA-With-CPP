#include<iostream>
using namespace std;

/* DIAMETER OF BINARY TREE

Given a Binary Tree, find its diameter.

Diameter:
The number of nodes on the longest path
between any two nodes in the tree.

Example:

           1
          / \
         2   3
        / \
       4   5

Output:
4

Explanation:
Longest path:
4 -> 2 -> 1 -> 3

Total nodes = 4
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

class Solution
{
public:

    int find(Node *root, int &ans)
    {
        if(!root)
            return 0;

        int left = find(root->left, ans);
        int right = find(root->right, ans);

        ans = max(ans, 1 + left + right);

        return 1 + max(left, right);
    }

    int diameter(Node* root)
    {
        int ans = 0;

        find(root, ans);

        return ans;
    }
};

int main()
{
    // Create Tree
    //
    //          1
    //         / \
    //        2   3
    //       / \
    //      4   5

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution obj;

    cout<<"Diameter of Tree: ";
    cout<<obj.diameter(root);

    return 0;
}