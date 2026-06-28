/*
DETECT CYCLE IN A DIRECTED GRAPH

Given a directed graph with V vertices and adjacency list adj[],
check whether the graph contains a cycle or not.

Approach:
1. Use DFS traversal.
2. Maintain two arrays:
   - visited[] -> node already visited
   - path[] -> node present in current DFS path
3. If during DFS we find a node already in path[],
   then cycle exists.

Example:
V = 4
Edges:
0 -> 1
1 -> 2
2 -> 3
3 -> 1

Output:
1
Explanation:
Cycle exists: 1 -> 2 -> 3 -> 1
*/

#include <iostream>
#include <vector>
using namespace std;

bool DFS(vector<int> adj[], vector<bool>& visited, vector<bool>& path, int node)
{
    visited[node] = true;
    path[node] = true;

    for (int i = 0; i < adj[node].size(); i++)
    {
        int nextNode = adj[node][i];

        if (!visited[nextNode])
        {
            if (DFS(adj, visited, path, nextNode))
                return true;
        }
        else
        {
            if (path[nextNode])
                return true;
        }
    }

    path[node] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    vector<bool> path(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (DFS(adj, visited, path, i))
                return true;
        }
    }
    return false;
}

int main()
{
    int V = 4;
    vector<int> adj[V];

    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1); // creates cycle

    if (isCyclic(V, adj))
        cout << "Cycle Found";
    else
        cout << "No Cycle";

    return 0;
}