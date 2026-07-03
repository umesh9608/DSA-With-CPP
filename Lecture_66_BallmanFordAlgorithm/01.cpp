/*
BELLMAN-FORD ALGORITHM

Given a weighted graph with V vertices and edges[],
find shortest distance from source S to all vertices.

Features:
- Works with negative weights
- Detects negative cycle

If negative cycle exists:
Return {-1}
*/

#include <iostream>
#include <vector>
using namespace std;

bool Bellman(vector<vector<int>>& edges, vector<int>& dist)
{
    bool noUpdate = true;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        if (dist[u] != 1e8 && dist[v] > dist[u] + wt)
        {
            dist[v] = dist[u] + wt;
            noUpdate = false;
        }
    }

    return noUpdate;
}

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S)
{
    vector<int> dist(V, 1e8);
    dist[S] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        if (Bellman(edges, dist))
            return dist;
    }

    // Check negative cycle
    if (!Bellman(edges, dist))
    {
        vector<int> temp;
        temp.push_back(-1);
        return temp;
    }

    return dist;
}

int main()
{
    int V = 5;
    vector<vector<int>> edges = {
        {0,1,5},
        {1,2,-2},
        {2,3,3},
        {3,4,1}
    };

    vector<int> ans = bellman_ford(V, edges, 0);

    for (int x : ans)
        cout << x << " ";

    return 0;
}