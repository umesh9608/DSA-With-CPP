#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

/* ZIGZAG TREE TRAVERSAL

Given a Binary Tree, find the Zig-Zag Level Order Traversal.

Example:

Input:

            1
          /   \
         2     3
        / \   / \
       4   5 6   7

Output:
1 3 2 4 5 6 7

Explanation:

Level 1 (Left -> Right): 1
Level 2 (Right -> Left): 3 2
Level 3 (Left -> Right): 4 5 6 7
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

vector<int> zigZagTraversal(Node* root)
{
    vector<int> ans;

    if(!root)
        return ans;

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty())
    {
        int size = q.size();

        vector<int> level(size);

        for(int i = 0; i < size; i++)
        {
            Node* temp = q.front();
            q.pop();

            int index;

            if(leftToRight)
                index = i;
            else
                index = size - 1 - i;

            level[index] = temp->data;

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }

        for(int x : level)
        {
            ans.push_back(x);
        }

        leftToRight = !leftToRight;
    }

    return ans;
}

int main()
{
    // Create Tree
    //
    //            1
    //          /   \
    //         2     3
    //        / \   / \
    //       4   5 6   7

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans = zigZagTraversal(root);

    cout << "ZigZag Traversal: ";

    for(int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}