/*  SUM OF K SMALLEST ELEMENT IN BST
  Given a Binary Search Tree. Find sum of all element m=smaller than and equal to Kth smallest element.
  Example: Input:                       20
                                      /  \ 
                                      8   22 
                                    / \   / \
                                    4  12
                                       /\
                                      10 14
   k=3
   Output:22
   Explanation:sum of 3 smallest element are: 4+8+10=22
   Your Task:
   You don't need to read input or print anything. Your task is to complete the function sum()  which takes the root and an integer K as input parameter and returns the sum of all elements smaller than and equal to Kth smallest element.

   Expected Time Complexity:O(K)
   Expected Axiliry space:O(1)

   constraints: 
   1<=Number of nodes in BST<=100
   1<=K<=N
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void Find(Node *root, int &k, int &total)
{
    if (!root || k == 0)
        return;

    Find(root->left, k, total);

    k--;
    if (k >= 0)
        total += root->data;

    Find(root->right, k, total);
}

int sum(Node* root, int k)
{
    int total = 0;
    Find(root, k, total);
    return total;
}

int main()
{
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    int k = 3;
    cout << sum(root, k);

    return 0;
}