/*
EULER CIRCUIT IN AN UNDIRECTED GRAPH

Given an undirected graph, check whether it contains
an Euler Circuit or not.

Conditions for Euler Circuit:
1. All vertices with non-zero degree must be connected.
2. Every vertex must have even degree.

Return:
1 -> Euler Circuit exists
0 -> Euler Circuit does not exist
*/

#include <iostream>
#include <vector>
using namespace std;

// DFS Traversal
void DFS(int node, vector<int> adj[], vector<bool>& visited)
{
    visited[node] = true;

    for (int i = 0; i < adj[node].size(); i++)
    {
        int next = adj[node][i];

        if (!visited[next])
            DFS(next, adj, visited);
    }
}

// Check Euler Circuit
bool isEulerCircuitExist(int V, vector<int> adj[])
{
    vector<int> degree(V, 0);

    // Calculate degree of every vertex
    for (int i = 0; i < V; i++)
        degree[i] = adj[i].size();

    // Find first vertex having non-zero degree
    int node = -1;
    for (int i = 0; i < V; i++)
    {
        if (degree[i] > 0)
        {
            node = i;
            break;
        }
    }

    // No edges in graph
    if (node == -1)
        return true;

    // Every vertex should have even degree
    for (int i = 0; i < V; i++)
    {
        if (degree[i] % 2 != 0)
            return false;
    }

    // Check connectivity
    vector<bool> visited(V, false);
    DFS(node, adj, visited);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && degree[i] > 0)
            return false;
    }

    return true;
}

int main()
{
    int V = 5;
    vector<int> adj[V];

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(0);
    adj[0].push_back(3);

    cout << isEulerCircuitExist(V, adj);

    return 0;
}