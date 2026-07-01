/*
MINIMUM SPANNING TREE (PRIM'S ALGORITHM)

Given a weighted undirected graph with V vertices and adjacency list adj[],
find the sum of weights of edges of the Minimum Spanning Tree (MST).

MST:
- Connects all vertices
- No cycle
- Minimum total edge weight

Example:
0 --2-- 1
|      /
6    3
|   /
2

Output:
5
(Edges: 0-1 and 1-2)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<int> weight(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> visited(V, false);

    int count = 0;
    int cost = 0;

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > q;

    q.push({0, 0});

    while (!q.empty())
    {
        int path = q.top().first;
        int node = q.top().second;
        q.pop();

        if (visited[node])
            continue;

        cost += path;
        count++;
        visited[node] = true;

        if (count == V)
            break;

        for (int i = 0; i < adj[node].size(); i++)
        {
            int adjNode = adj[node][i][0];
            int adjPath = adj[node][i][1];

            if (!visited[adjNode] && adjPath < weight[adjNode])
            {
                q.push({adjPath, adjNode});
                parent[adjNode] = node;
                weight[adjNode] = adjPath;
            }
        }
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