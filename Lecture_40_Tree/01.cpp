#include <iostream>
using namespace std;
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

Node *BinaryTree()
{
  int x;
  cout << "Enter The Value: ";
  cin >> x;
  if (x == -1)
    return NULL;

    Node *root = new Node(x);
    cout<<"Ente The Left Child Of  "<<x<<"\n";
    root->left=BinaryTree();
    cout<<"Enter The Right Child Of "<<x<<"\n";
    root->right=BinaryTree();
}

void Inorder(Node *root)
{
  if(!root)
  return;
  Inorder(root->left);
  cout<<root->data<<" ";
  Inorder(root->right);
  return;
}

void Postorder(Node *root)
{
  if(!root)
  return;
  Postorder(root->left);
  Postorder(root->right);
  cout<<root->data<<" ";
  return;
}


void Preorder(Node *root)
{
  if(!root)
  return;
  cout<<root->data<<" ";
  Preorder(root->left);
  Preorder(root->right);
  
  return;
}

int main()
{
Node *root = BinaryTree();
cout<<"Inorder Traversal: ";
Inorder(root);
cout<<endl;


cout<<"Postorder Traversal: ";
Postorder(root);
cout<<endl;


cout<<"Preorder Traversal: ";
Preorder(root);
cout<<endl;
  return 0;
}

/*
Enter The Value: 1
Ente The Left Child Of  1
Enter The Value: 2
Ente The Left Child Of  2
Enter The Value: 3
Ente The Left Child Of  3
Enter The Value: -1
Enter The Right Child Of 3
Enter The Value: -1
Enter The Right Child Of 2
Enter The Value: 4
Ente The Left Child Of  4
Enter The Value: -1
Enter The Right Child Of 4
Enter The Value: -1
Enter The Right Child Of 1
Enter The Value: 5
Ente The Left Child Of  5
Enter The Value: 6
Ente The Left Child Of  6
Enter The Value: -1
Enter The Right Child Of 6
Enter The Value: -1
Enter The Right Child Of 5
Enter The Value: 7
Ente The Left Child Of  7
Enter The Value: -1
Enter The Right Child Of 7
Enter The Value: -1
Inorder Traversal: 3 2 4 1 6 5 7 
Postorder Traversal: 3 4 2 6 7 5 1 
Preorder Traversal: 1 2 3 4 5 6 7 
*/