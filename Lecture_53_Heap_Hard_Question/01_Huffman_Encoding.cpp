/*
HUFFMAN ENCODING

Given a string S of distinct characters and their frequencies f[],
build Huffman Tree and print Huffman codes in preorder traversal.

Example:
S = "abcdef"
f = {5, 9, 12, 13, 16, 45}

Output:
0 100 101 1100 1101 111
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
  class Node
  {
  public:
    int freq;
    Node *left, *right;

    Node(int count)
    {
      freq = count;
      left = right = NULL;
    }
  };

  class compare
  {
  public:
    bool operator()(Node *a, Node *b)
    {
      return a->freq > b->freq;
    }
  };

  void pre_order(Node *root, string s, vector<string> &huff)
  {
    if (!root)
      return;

    if (!root->left && !root->right)
    {
      huff.push_back(s);
      return;
    }

    pre_order(root->left, s + '0', huff);
    pre_order(root->right, s + '1', huff);
  }

  vector<string> huffmanCodes(string S, vector<int> f, int N)
  {
    priority_queue<Node *, vector<Node *>, compare> minheap;

    for (int i = 0; i < N; i++)
    {
      Node *node = new Node(f[i]);
      minheap.push(node);
    }

    Node *root = NULL;

    while (minheap.size() > 1)
    {
      Node *min1 = minheap.top();
      minheap.pop();

      Node *min2 = minheap.top();
      minheap.pop();

      root = new Node(min1->freq + min2->freq);
      root->left = min1;
      root->right = min2;

      minheap.push(root);
    }

    root = minheap.top();

    vector<string> huff;
    pre_order(root, "", huff);

    return huff;
  }
};

int main()
{
  Solution obj;

  string S = "abcdef";
  vector<int> f = {5, 9, 12, 13, 16, 45};

  vector<string> ans = obj.huffmanCodes(S, f, S.size());

  for (string code : ans)
    cout << code << " ";

  return 0;
}

// 1hr