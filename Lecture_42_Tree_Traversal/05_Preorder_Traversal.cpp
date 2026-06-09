#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/* PREORDER TRAVERSAL (ITERATIVE)

Given a binary tree, find preorder traversal
without using recursion.

Preorder:
Root -> Left -> Right

Example:

Input:

           1
          / \
         2   3
        / \
       4   5

Output:
1 2 4 5 3

Explanation:
Preorder traversal:
1 -> 2 -> 4 -> 5 -> 3
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

    vector<int> preOrder(Node* root)
    {
        vector<int> ans;

        if(!root)
            return ans;

        stack<Node*> s;
        s.push(root);

        while(!s.empty())
        {
            Node* temp = s.top();
            s.pop();

            ans.push_back(temp->data);

            // Right first
            if(temp->right)
                s.push(temp->right);

            // Left second
            if(temp->left)
                s.push(temp->left);
        }

        return ans;
    }
};

int main()
{
    // Create Tree
    //
    //           1
    //          / \
    //         2   3
    //        / \
    //       4   5

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution obj;

    vector<int> result = obj.preOrder(root);

    cout<<"Preorder Traversal: ";

    for(int x : result)
    {
        cout<<x<<" ";
    }

    return 0;
}