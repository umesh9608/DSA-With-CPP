#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

/* LEVEL ORDER TRAVERSAL IN SPIRAL FORM

Complete the function to find spiral traversal of a tree.

Example 1:

                1
               / \
              2   3
             / \ / \
            7  6 5  4

Output:
1 2 3 4 5 6 7

Example 2:

                1
               / \
              3   2

Output:
1 3 2
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

vector<int> findSpiral(Node *root)
{
    vector<int> ans;

    if(!root)
        return ans;

    queue<Node*> q;
    stack<Node*> s;

    q.push(root);

    bool dir = 0;

    while(!q.empty())
    {
        int size = q.size();

        if(dir == 0)
        {
            while(size--)
            {
                Node* temp = q.front();
                q.pop();

                ans.push_back(temp->data);

                if(temp->right)
                    s.push(temp->right);

                if(temp->left)
                    s.push(temp->left);
            }

            dir = 1;
        }
        else
        {
            while(size--)
            {
                Node* temp = q.front();
                q.pop();

                ans.push_back(temp->data);

                if(temp->left)
                    s.push(temp->left);

                if(temp->right)
                    s.push(temp->right);
            }

            dir = 0;
        }

        while(!s.empty())
        {
            q.push(s.top());
            s.pop();
        }
    }

    return ans;
}

int main()
{
    // Tree
    //
    //          1
    //        /   \
    //       2     3
    //      / \   / \
    //     7  6 5   4

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(7);
    root->left->right = new Node(6);

    root->right->left = new Node(5);
    root->right->right = new Node(4);

    vector<int> ans = findSpiral(root);

    cout<<"Spiral Traversal: ";

    for(int x : ans)
        cout<<x<<" ";

    return 0;
}