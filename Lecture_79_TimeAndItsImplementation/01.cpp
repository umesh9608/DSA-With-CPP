/*
TRIE DATA STRUCTURE

A Trie is a tree-like data structure used to store strings.

Operations:
1. Insert a word
2. Search for a complete word

Example:
Insert:
apple
applx
almond

Search:
apple -> Found
app   -> Not Found
*/

#include <iostream>
#include <string>
using namespace std;

class TrieNode
{
public:
    TrieNode* child[26];
    bool isEndOfWord;

    TrieNode()
    {
        isEndOfWord = false;

        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
    }
};

class Trie
{
    TrieNode* root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    // Insert a word
    void insert(string word)
    {
        TrieNode* node = root;

        for (char c : word)
        {
            int index = c - 'a';

            if (node->child[index] == NULL)
            {
                node->child[index] = new TrieNode();
            }

            node = node->child[index];
        }

        node->isEndOfWord = true;
    }

    // Search a complete word
    bool search(string word)
    {
        TrieNode* node = root;

        for (char c : word)
        {
            int index = c - 'a';

            if (node->child[index] == NULL)
            {
                return false;
            }

            node = node->child[index];
        }

        return node->isEndOfWord;
    }
};

int main()
{
    Trie* tree = new Trie();
    

    tree->insert("apple");
    tree->insert("applx");
    tree->insert("almond");

    cout << "Does apple exist: "
         << tree->search("apple") << endl;

    cout << "Does app exist: "
         << tree->search("app") << endl;

    return 0;
}