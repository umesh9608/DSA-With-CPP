/*
SEGMENT TREE: RANGE MAXIMUM QUERY + UPDATE

Given an array, build a Segment Tree that supports:

1. Finding the maximum element in a given range [left, right]
2. Updating the value at a specific index

Example:
Array = {3, 6, 4, 25, 5, 13, 8}

Query:
Range = [2, 5]

Maximum = 25

Update:
Index = 2
Value = 30

New Array:
{3, 6, 30, 25, 5, 13, 8}
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class SegmentTree
{
    vector<int> tree;
    vector<int> arr;
    int n;

public:

    SegmentTree(vector<int> input)
    {
        arr = input;
        n = arr.size();

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

        build(2 * node + 1, start, mid);
        build(2 * node + 2, mid + 1, end);

        tree[node] = max(
            tree[2 * node + 1],
            tree[2 * node + 2]
        );
    }

    // Range Maximum Query
    int range(int node, int start, int end,
              int left, int right)
    {
        // No Overlap
        if (end < left || start > right)
        {
            return INT_MIN;
        }

        // Complete Overlap
        if (start >= left && end <= right)
        {
            return tree[node];
        }

        int mid = start + (end - start) / 2;

        return max(
            range(2 * node + 1, start, mid, left, right),
            range(2 * node + 2, mid + 1, end, left, right)
        );
    }

    // Query Wrapper Function
    int query(int left, int right)
    {
        return range(0, 0, n - 1, left, right);
    }

    // Update Helper Function
    void updating(int node, int start, int end,
                  int idx, int value)
    {
        // Index not in current range
        if (idx < start || idx > end)
        {
            return;
        }

        // Leaf Node
        if (start == end)
        {
            tree[node] = value;
            return;
        }

        int mid = start + (end - start) / 2;

        if (idx <= mid)
        {
            updating(
                2 * node + 1,
                start,
                mid,
                idx,
                value
            );
        }
        else
        {
            updating(
                2 * node + 2,
                mid + 1,
                end,
                idx,
                value
            );
        }

        // Update current node
        tree[node] = max(
            tree[2 * node + 1],
            tree[2 * node + 2]
        );
    }

    // Update Wrapper Function
    void update(int idx, int value)
    {
        arr[idx] = value;

        updating(
            0,
            0,
            n - 1,
            idx,
            value
        );
    }
};

int main()
{
    vector<int> arr = {
        3, 6, 4, 25, 5, 13, 8
    };

    SegmentTree tree(arr);

    cout << "Maximum in range [2, 5]: "
         << tree.query(2, 5) << endl;

    tree.update(2, 30);

    cout << "After update:" << endl;

    cout << "Maximum in range [2, 5]: "
         << tree.query(2, 5) << endl;

    return 0;
}