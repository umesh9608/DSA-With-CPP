/*
GRAPH REPRESENTATION USING ADJACENCY LIST

Write a C++ program to represent an undirected graph
using adjacency list.

Input:
Number of vertices (V)
Number of edges (E)
Then E pairs of vertices (a, b)

Example:
Input:
5 4
0 1
0 2
1 3
3 4

Output:
0 -> 1 2
1 -> 0 3
2 -> 0
3 -> 1 4
4 -> 3
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;

    vector<int> A[v];

    int a, b;

    for (int i = 0; i < e; i++)
    {
        cin >> a >> b;

        A[a].push_back(b);
        A[b].push_back(a);
    }

    // Print adjacency list
    for (int i = 0; i < v; i++)
    {
        cout << i << " -> ";
        for (int node : A[i])
            cout << node << " ";
        cout << endl;
    }

    return 0;
}