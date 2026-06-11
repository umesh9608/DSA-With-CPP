#include<iostream>
#include<climits>
using namespace std;

/* MAXIMUM PATH SUM BETWEEN 2 SPECIAL NODES

Given a binary tree in which node elements contain numbers,
find the maximum possible path sum from one special node
to another special node.

Note:
A special node is a node connected to exactly one different node
(i.e., a leaf node).

Example:

                3
               / \
              4   5
             / \
           -10  4

Output:
16

Explanation:
Maximum path sum lies between leaf node 4 and leaf node 5.

Path:
4 -> 4 -> 3 -> 5

Sum:
4 + 4 + 3 + 5 = 16
*/

class Node
{
public:
    int data;
    Node *left;
    Node *right;

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

    int solve(Node *root, int &ans)
    {
        if(!root)
            return 0;

        // Leaf node
        if(!root->left && !root->right)
            return root->data;

        int left = solve(root->left, ans);
        int right = solve(root->right, ans);

        // If both children exist
        if(root->left && root->right)
        {
            ans = max(ans, left + right + root->data);

            return root->data + max(left, right);
        }

        // If only one child exists
        if(root->left)
            return root->data + left;
        else
            return root->data + right;
    }

    int maxPathSum(Node *root)
    {
        int ans = INT_MIN;

        int temp = solve(root, ans);

        // Handle skew tree
        if(!root->left || !root->right)
            ans = max(ans, temp);

        return ans;
    }
};

int main()
{
    // Create Tree
    //
    //          3
    //         / \
    //        4   5
    //       / \
    //    -10   4

    Node *root = new Node(3);

    root->left = new Node(4);
    root->right = new Node(5);

    root->left->left = new Node(-10);
    root->left->right = new Node(4);

    Solution obj;

    cout << "Maximum Path Sum = "
         << obj.maxPathSum(root);

    return 0;
}