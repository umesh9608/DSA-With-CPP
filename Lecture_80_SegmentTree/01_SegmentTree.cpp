/*
SEGMENT TREE

Given an array, build a Segment Tree to find the sum
of elements in a given range [left, right].

Example:
Array = {3, 6, 4, 25, 5, 13, 8}

Query:
Range = [2, 5]

Sum = 4 + 25 + 5 + 13 = 47
*/

#include <iostream>
#include <vector>
using namespace std;

class SegmentTree
{
    vector<int> tree;
    vector<int> arr;
    int n;

public:

    // Constructor
    SegmentTree(vector<int> input)
    {
        n = input.size();
        arr = input;

        tree.resize(4 * n);

        build(0, 0, n - 1);
    }

    // Build Segment Tree
    void build(int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = arr[start];
            return;
        }

        int mid = start + (end - start) / 2;

        // Build left subtree
        build(2 * node + 1, start, mid);

        // Build right subtree
        build(2 * node + 2, mid + 1, end);

        // Store sum of both children
        tree[node] =
            tree[2 * node + 1] +
            tree[2 * node + 2];
    }

    // Query function
    int query(int left, int right)
    {
        return rangeQuery(0, 0, n - 1, left, right);
    }

    // Range Query
    int rangeQuery(int node, int start, int end,
                   int left, int right)
    {
        // No overlap
        if (end < left || start > right)
        {
            return 0;
        }

        // Complete overlap
        if (start >= left && end <= right)
        {
            return tree[node];
        }

        int mid = start + (end - start) / 2;

        int leftSum = rangeQuery(
            2 * node + 1,
            start,
            mid,
            left,
            right
        );

        int rightSum = rangeQuery(
            2 * node + 2,
            mid + 1,
            end,
            left,
            right
        );

        return leftSum + rightSum;
    }
};

int main()
{
    vector<int> arr = {
        3, 6, 4, 25, 5, 13, 8
    };

    SegmentTree tree(arr);

    cout << "Sum of range [2, 5]: "
         << tree.query(2, 5) << endl;

    return 0;
}