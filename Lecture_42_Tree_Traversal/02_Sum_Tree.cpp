#include<iostream>
using namespace std;

/* SUM TREE

Given a Binary Tree, return true if every node
(other than leaf nodes) is equal to the sum of
its left subtree and right subtree values.

Empty tree and leaf nodes are also considered
Sum Trees.

Example 1:

         3
        / \
       1   2

Output:
1

Explanation:
1 + 2 = 3


Example 2:

          10
         /  \
        20   30
       / \
      10 10

Output:
0
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
    int SumTree(Node *root, bool &ans)
    {
        if(!root)
            return 0;

        // Leaf node
        if(!root->left && !root->right)
            return root->data;

        // Left subtree sum
        int left = SumTree(root->left, ans);

        // Right subtree sum
        int right = SumTree(root->right, ans);

        if(left + right != root->data)
            ans = false;

        return root->data + left + right;
    }

public:

    bool isSumTree(Node *root)
    {
        bool ans = true;

        SumTree(root, ans);

        return ans;
    }
};

int main()
{
    // Create Tree
    //
    //       3
    //      / \
    //     1   2

    Node* root = new Node(3);

    root->left = new Node(1);
    root->right = new Node(2);

    Solution obj;

    if(obj.isSumTree(root))
        cout<<"1";
    else
        cout<<"0";

    return 0;
}