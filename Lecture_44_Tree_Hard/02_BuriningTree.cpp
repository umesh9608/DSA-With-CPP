#include<iostream>
#include<queue>
#include<map>
using namespace std;

/* BURNING TREE

Given a binary tree and a target node, find the minimum
time required to burn the complete binary tree if the
target node is set on fire.

In 1 second, fire spreads to:
1. Left child
2. Right child
3. Parent

Tree contains unique values.

Example:

                 1
               /   \
              2     3
             / \     \
            4   5     6
               / \     \
              7   8     9
                         \
                          10

Target Node = 8

Output: 7
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

    // Create parent mapping and find target node
    Node* createParentMapping(Node* root,
                              map<Node*, Node*>& parent,
                              int target)
    {
        queue<Node*> q;
        q.push(root);

        Node* targetNode = NULL;

        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();

            if(temp->data == target)
                targetNode = temp;

            if(temp->left)
            {
                parent[temp->left] = temp;
                q.push(temp->left);
            }

            if(temp->right)
            {
                parent[temp->right] = temp;
                q.push(temp->right);
            }
        }

        return targetNode;
    }

    int burnTree(Node* targetNode,
                 map<Node*, Node*>& parent)
    {
        map<Node*, bool> visited;
        queue<Node*> q;

        q.push(targetNode);
        visited[targetNode] = true;

        int time = 0;

        while(!q.empty())
        {
            int size = q.size();
            bool burned = false;

            while(size--)
            {
                Node* temp = q.front();
                q.pop();

                // Left child
                if(temp->left && !visited[temp->left])
                {
                    burned = true;
                    visited[temp->left] = true;
                    q.push(temp->left);
                }

                // Right child
                if(temp->right && !visited[temp->right])
                {
                    burned = true;
                    visited[temp->right] = true;
                    q.push(temp->right);
                }

                // Parent
                if(parent[temp] && !visited[parent[temp]])
                {
                    burned = true;
                    visited[parent[temp]] = true;
                    q.push(parent[temp]);
                }
            }

            if(burned)
                time++;
        }

        return time;
    }

    int minTime(Node* root, int target)
    {
        map<Node*, Node*> parent;

        Node* targetNode =
            createParentMapping(root, parent, target);

        return burnTree(targetNode, parent);
    }
};

int main()
{
    /*
                 1
               /   \
              2     3
             / \     \
            4   5     6
               / \     \
              7   8     9
                         \
                          10
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);

    root->right->right = new Node(6);
    root->right->right->right = new Node(9);
    root->right->right->right->right = new Node(10);

    int target = 8;

    Solution obj;

    cout << "Minimum Time = "
         << obj.minTime(root, target);

    return 0;
}