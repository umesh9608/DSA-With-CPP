/*
BRIDGE IN GRAPH

Given an undirected graph and an edge (c, d),
check whether that edge is a bridge or not.

Bridge:
An edge is called bridge if removing it increases
the number of connected components.

Example:
0 -- 1 -- 2
     |
     3

Edge (1,2) is a bridge.
*/

#include <iostream>
#include <vector>
using namespace std;

bool DFS(int node, int target, vector<int> adj[], vector<bool>& visited)
{
    if (node == target)
        return true;

    visited[node] = true;

    for (int i = 0; i < adj[node].size(); i++)
    {
        int next = adj[node][i];

        if (!visited[next])
        {
            if (DFS(next, target, adj, visited))
                return true;
        }
    }

    return false;
}

int isBridge(int V, vector<int> adj[], int c, int d)
{
    // Remove edge c-d
    for (int i = 0; i < adj[c].size(); i++)
    {
        if (adj[c][i] == d)
        {
            adj[c][i] = c;
            break;
        }
    }

    // Remove edge d-c
    for (int i = 0; i < adj[d].size(); i++)
    {
        if (adj[d][i] == c)
        {
            adj[d][i] = d;
            break;
        }
    }

    vector<bool> visited(V, false);

    if (DFS(c, d, adj, visited))
        return 0; // Not bridge
    else
        return 1; // Bridge
}

int main()
{
    int V = 4;
    vector<int> adj[V];

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(3);
    adj[3].push_back(1);

    cout << isBridge(V, adj, 1, 2);

    return 0;
}