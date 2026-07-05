/*
CRITICAL CONNECTIONS IN A NETWORK (BRIDGES)

Given an undirected connected graph with V vertices and adjacency list adj[],
find all the critical connections (bridges).

A bridge is an edge whose removal increases the number of connected components.

Algorithm: Tarjan's Algorithm (DFS)

Time Complexity: O(V + E)
Space Complexity: O(V)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int DFS(int node,
        vector<int> adj[],
        vector<int>& disc,
        vector<int>& low,
        vector<vector<int>>& bridge,
        int& timer,
        int parent)
{
    disc[node] = low[node] = ++timer;

    for (int i = 0; i < adj[node].size(); i++)
    {
        int neighbour = adj[node][i];

        // Ignore parent
        if (neighbour == parent)
            continue;

        // Back Edge
        if (disc[neighbour] != -1)
        {
            low[node] = min(low[node], disc[neighbour]);
        }
        else
        {
            DFS(neighbour, adj, disc, low, bridge, timer, node);

            low[node] = min(low[node], low[neighbour]);

            // Bridge Condition
            if (low[neighbour] > disc[node])
            {
                if (node < neighbour)
                    bridge.push_back({node, neighbour});
                else
                    bridge.push_back({neighbour, node});
            }
        }
    }

    return low[node];
}

vector<vector<int>> criticalConnections(int V, vector<int> adj[])
{
    vector<vector<int>> bridge;

    vector<int> disc(V, -1);
    vector<int> low(V, -1);

    int timer = 0;

    // Handle disconnected graph
    for (int i = 0; i < V; i++)
    {
        if (disc[i] == -1)
            DFS(i, adj, disc, low, bridge, timer, -1);
    }

    sort(bridge.begin(), bridge.end());

    return bridge;
}

int main()
{
    int V = 5;

    vector<int> adj[V];

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(0);
    adj[0].push_back(2);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[3].push_back(4);
    adj[4].push_back(3);

    vector<vector<int>> ans = criticalConnections(V, adj);

    cout << "Bridges are:\n";

    for (auto edge : ans)
    {
        cout << edge[0] << " " << edge[1] << endl;
    }

    return 0;
}