#include<iostream>
using namespace std;

/* ROOT TO LEAF PATH SUM

Given a binary tree where every node contains
a number, find the sum of all numbers formed
from root-to-leaf paths.

Example:

                    6
                  /   \
                 3     5
                / \     \
               2   5     4
                  / \
                 7   4

Output:
13997

Explanation:

Path          Number
6->3->2       632
6->3->5->7    6357
6->3->5->4    6354
6->5->4       654

Answer:
632 + 6357 + 6354 + 654 = 13997
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

void FindSum(Node *root, long long &sum, long long num)
{
    if(!root)
        return;

    // Form current number
    num = num * 10 + root->data;

    // Leaf node
    if(!root->left && !root->right)
    {
        sum += num;
        return;
    }

    FindSum(root->left, sum, num);
    FindSum(root->right, sum, num);
}

long long treePathSum(Node *root)
{
    long long sum = 0;
    long long num = 0;

    FindSum(root, sum, num);

    return sum;
}

int main()
{
    // Create Tree
    //
    //                6
    //              /   \
    //             3     5
    //            / \     \
    //           2   5     4
    //              / \
    //             7   4

    Node* root = new Node(6);

    root->left = new Node(3);
    root->right = new Node(5);

    root->left->left = new Node(2);
    root->left->right = new Node(5);

    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    root->right->right = new Node(4);

    cout<<"Root to Leaf Path Sum: ";
    cout<<treePathSum(root);

    return 0;
}