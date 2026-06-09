#include<iostream>
#include<vector>
using namespace std;

/* NODES AT ODD LEVELS

Given a Binary Tree of size N,
find all nodes at odd levels.

Root is considered at level 1.

Example:

              1
            /   \
           2     3
          / \   /
         4   5 6
            / \ /
           7  8 9

Output:
1 4 5 6
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

    void PreOrder(Node *root, vector<int>& ans, int level)
    {
        if(!root)
            return;

        if(level % 2 == 1)
            ans.push_back(root->data);

        PreOrder(root->left, ans, level+1);
        PreOrder(root->right, ans, level+1);
    }

    vector<int> nodeAtOddLevels(Node *root)
    {
        vector<int> ans;

        PreOrder(root, ans, 1);

        return ans;
    }
};

int main()
{
    // Create Tree
    //
    //              1
    //            /   \
    //           2     3
    //          / \   /
    //         4   5 6
    //            / \ /
    //           7  8 9

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);

    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);

    root->right->left->left = new Node(9);

    Solution obj;

    vector<int> result = obj.nodeAtOddLevels(root);

    cout<<"Nodes at Odd Levels: ";

    for(int x : result)
    {
        cout<<x<<" ";
    }

    return 0;
}