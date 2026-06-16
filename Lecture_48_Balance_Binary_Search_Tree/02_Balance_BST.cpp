#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

Node* CreateBBST(vector<int>& v, int start, int end)
{
    if (start > end)
        return NULL;

    int mid = start + (end - start) / 2;
    Node* root = new Node(v[mid]);

    root->left = CreateBBST(v, start, mid - 1);
    root->right = CreateBBST(v, mid + 1, end);

    return root;
}

void inorder(Node* root)
{
    if (!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    int n;
    cout << "Enter no: ";
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    Node* root = CreateBBST(v, 0, n - 1);

    cout << "Balanced BST Inorder: ";
    inorder(root);

    return 0;
}