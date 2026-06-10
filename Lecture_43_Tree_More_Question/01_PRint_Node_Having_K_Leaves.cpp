#include<iostream>
#include<vector>
using namespace std;

/* PRINT NODES HAVING K LEAVES

Given a binary tree and an integer K,
find all nodes having exactly K leaves
in the subtree rooted at them.

Nodes should be printed in Postorder Traversal order.

Example:

          0
         / \
        1   2

K = 1

Output:
-1

Explanation:
No node has exactly 1 leaf in its subtree.
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

    int Find(Node *root, vector<int>& count, int k)
    {
        if(!root)
            return 0;

        // Leaf node
        if(!root->left && !root->right)
            return 1;

        int left = Find(root->left, count, k);
        int right = Find(root->right, count, k);

        if(left + right == k)
            count.push_back(root->data);

        return left + right;
    }

    vector<int> btWithKLeaves(Node *ptr, int k)
    {
        vector<int> count;

        Find(ptr, count, k);

        return count;
    }
};

int main()
{
    // Tree
    //
    //         0
    //        / \
    //       1   2

    Node* root = new Node(0);

    root->left = new Node(1);
    root->right = new Node(2);

    int k = 1;

    Solution obj;

    vector<int> ans = obj.btWithKLeaves(root, k);

    if(ans.empty())
    {
        cout << -1;
    }
    else
    {
        for(int x : ans)
            cout << x << " ";
    }

    return 0;
}