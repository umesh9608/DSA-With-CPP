#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/* LEFT VIEW OF BINARY TREE

Given a binary tree, return its left view.

Left view of a binary tree:
Set of nodes visible when tree is viewed
from the left side.

Example:

Left view = 1 2 4 8

          1
         / \
        2   3
       / \ / \
      4  5 6  7
       \
        8
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

vector<int> leftView(Node *root)
{
    vector<int> ans;

    if(root == NULL)
        return ans;

    queue<Node*> q;

    q.push(root);

    while(!q.empty())
    {
        int size = q.size();

        // First node of level
        ans.push_back(q.front()->data);

        while(size--)
        {
            Node* temp = q.front();
            q.pop();

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }
    }

    return ans;
}

int main()
{
    // Create tree
    //
    //          1
    //         / \
    //        2   3
    //       / \ / \
    //      4  5 6 7
    //       \
    //        8

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->left->left->right = new Node(8);

    vector<int> result = leftView(root);

    cout<<"Left View: ";

    for(int x : result)
    {
        cout<<x<<" ";
    }

    return 0;
}