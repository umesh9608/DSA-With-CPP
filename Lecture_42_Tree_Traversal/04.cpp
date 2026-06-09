#include<iostream>
using namespace std;

/* MAXIMUM DIFFERENCE BETWEEN NODE AND ITS ANCESTOR

Given a Binary Tree, find the maximum value
obtained by:

Ancestor Node Value - Descendant Node Value

where A is an ancestor of B.

Example:

          5
         / \
        2   1

Output:
4

Explanation:
Maximum difference:
5 - 1 = 4
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

void Find(Node *root, int Anc_max, int &Diff)
{
    if(!root)
        return;

    Diff = max(Diff, Anc_max - root->data);

    Anc_max = max(Anc_max, root->data);

    Find(root->left, Anc_max, Diff);
    Find(root->right, Anc_max, Diff);
}

int maxDiff(Node* root)
{
    if(!root)
        return 0;

    int Diff = 0;

    Find(root->left, root->data, Diff);
    Find(root->right, root->data, Diff);

    return Diff;
}

int main()
{
    // Create Tree
    //
    //          5
    //         / \
    //        2   1

    Node* root = new Node(5);

    root->left = new Node(2);
    root->right = new Node(1);

    cout<<"Maximum Difference: ";
    cout<<maxDiff(root);

    return 0;
}