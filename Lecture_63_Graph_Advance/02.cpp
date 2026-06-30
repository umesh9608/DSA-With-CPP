/*
DIJKSTRA ALGORITHM

Given a weighted graph with V vertices and adjacency list adj[],
find the shortest distance from source node S to all vertices.

Condition:
- Edge weights must be positive.

Example:
0 --4--> 1
0 --1--> 2
2 --2--> 1

Source = 0

Output:
0 3 1
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> dist(V, -1);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > q;

    q.push({0, S});

    while (!q.empty())
    {
        int step = q.top().first;
        int node = q.top().second;
        q.pop();

        if (dist[node] != -1)
            continue;

        dist[node] = step;

        for (int i = 0; i < adj[node].size(); i++)
        {
            int nextNode = adj[node][i][0];
            int weight = adj[node][i][1];

            if (dist[nextNode] == -1)
            {
                q.push({step + weight, nextNode});
            }
        }
    }

    return dist;
}

int main()
{
    int V = 3;
    vector<vector<int>> adj[V];

    adj[0].push_back({1, 4});
    adj[0].push_back({2, 1});
    adj[2].push_back({1, 2});

    vector<int> ans = dijkstra(V, adj, 0);

    for (int x : ans)
        cout << x << " ";

    return 0;
}