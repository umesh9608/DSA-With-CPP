#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

/* LARGEST VALUE IN EACH LEVEL

Given a binary tree, find the largest value
at each level.

Example:

Input:

          1
         / \
        2   3

Output:
1 3

Explanation:

Level 1: {1}     -> Max = 1
Level 2: {2,3}   -> Max = 3
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

vector<int> largestValue(Node* root)
{
    vector<int> ans;

    if(!root)
        return ans;

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int size = q.size();
        int maxi = INT_MIN;

        while(size--)
        {
            Node* temp = q.front();
            q.pop();

            maxi = max(maxi, temp->data);

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }

        ans.push_back(maxi);
    }

    return ans;
}

int main()
{
    // Create Tree
    //
    //          1
    //         / \
    //        2   3

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    vector<int> result = largestValue(root);

    cout<<"Largest value at each level: ";

    for(int x : result)
    {
        cout<<x<<" ";
    }

    return 0;
}