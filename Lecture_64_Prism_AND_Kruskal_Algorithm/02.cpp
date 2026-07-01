/*
MINIMUM SPANNING TREE (KRUSKAL ALGORITHM)

Given a weighted undirected graph with V vertices and adjacency list adj[],
find the total weight of Minimum Spanning Tree using Kruskal Algorithm.

Algorithm:
1. Sort all edges by weight
2. Pick smallest edge
3. Add edge if it does not create cycle
4. Use Disjoint Set (Union Find)

Time Complexity:
O(E log E)
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int find_parent(int u, vector<int>& parent)
{
    if (u == parent[u])
        return u;

    return parent[u] = find_parent(parent[u], parent);
}

bool unionSet(int u, int v, vector<int>& rank, vector<int>& parent)
{
    int pu = find_parent(u, parent);
    int pv = find_parent(v, parent);

    if (pu == pv)
        return true; // cycle

    if (rank[pu] == rank[pv])
    {
        rank[pu]++;
        parent[pv] = pu;
    }
    else if (rank[pu] < rank[pv])
    {
        parent[pu] = pv;
    }
    else
    {
        parent[pv] = pu;
    }

    return false;
}

int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<int> parent(V);
    vector<int> rank(V, 0);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    priority_queue<
        pair<pair<int, int>, int>,
        vector<pair<pair<int, int>, int>>,
        greater<pair<pair<int, int>, int>>
    > q;

    int u, v, w;

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            u = i;
            v = adj[i][j][0];
            w = adj[i][j][1];

            q.push({{w, u}, v});
        }
    }

    int count_edge = 0;
    int cost = 0;

    while (!q.empty())
    {
        if (count_edge == V - 1)
            break;

        w = q.top().first.first;
        u = q.top().first.second;
        v = q.top().second;
        q.pop();

        if (unionSet(u, v, rank, parent))
            continue;

        count_edge++;
        cost += w;
    }

    return cost;
}

int main()
{
    int V = 3;
    vector<vector<int>> adj[V];

    adj[0].push_back({1, 2});
    adj[0].push_back({2, 6});

    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});

    adj[2].push_back({0, 6});
    adj[2].push_back({1, 3});

    cout << spanningTree(V, adj);

    return 0;
}