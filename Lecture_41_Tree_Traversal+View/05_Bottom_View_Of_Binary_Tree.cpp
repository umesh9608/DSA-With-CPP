#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

/* BOTTOM VIEW OF BINARY TREE

Given a binary tree, print the bottom view
from left to right.

A node is included in bottom view if it is
visible when the tree is viewed from bottom.

Example:

                     20
                    /  \
                   8    22
                  / \     \
                 5   3     25
                    / \
                   10 14

Output:
5 10 3 14 25

Explanation:
The bottom-most node at each horizontal
distance is selected.
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

    vector<int> bottomView(Node *root)
    {
        vector<int> ans;

        if(!root)
            return ans;

        map<int,int> mp;

        // node , horizontal distance
        queue<pair<Node*,int>> q;

        q.push({root,0});

        while(!q.empty())
        {
            Node* temp = q.front().first;
            int hd = q.front().second;
            q.pop();

            // overwrite value
            mp[hd] = temp->data;

            if(temp->left)
                q.push({temp->left,hd-1});

            if(temp->right)
                q.push({temp->right,hd+1});
        }

        for(auto x : mp)
        {
            ans.push_back(x.second);
        }

        return ans;
    }
};

int main()
{
    Node* root = new Node(20);

    root->left = new Node(8);
    root->right = new Node(22);

    root->left->left = new Node(5);
    root->left->right = new Node(3);

    root->right->right = new Node(25);

    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    Solution obj;

    vector<int> result = obj.bottomView(root);

    cout<<"Bottom View: ";

    for(int x : result)
    {
        cout<<x<<" ";
    }

    return 0;
}