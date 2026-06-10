#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* PRINT BINARY TREE LEVELS IN SORTED ORDER

Given an array arr[] which contains data of N nodes
of a Complete Binary Tree in level order fashion.

The task is to print the level order traversal
such that nodes at each level are printed in sorted order.

Example:

Input:
N = 7
arr[] = {7, 6, 5, 4, 3, 2, 1}

Output:
7
5 6
1 2 3 4

Explanation:

The formed Binary Tree is:

                 7
               /   \
              6     5
             / \   / \
            4   3 2   1

Level 1 -> {7}       -> 7
Level 2 -> {6,5}     -> 5 6
Level 3 -> {4,3,2,1} -> 1 2 3 4
*/

class Solution{
public:

    void printSortedLevels(int arr[], int n)
    {
        int index = 0;
        int levelSize = 1;

        while(index < n)
        {
            vector<int> level;

            for(int i = 0; i < levelSize && index < n; i++)
            {
                level.push_back(arr[index++]);
            }

            sort(level.begin(), level.end());

            for(int x : level)
            {
                cout << x << " ";
            }

            cout << endl;

            levelSize *= 2;
        }
    }
};

int main()
{
    int arr[] = {7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    Solution obj;
    obj.printSortedLevels(arr, n);

    return 0;
}