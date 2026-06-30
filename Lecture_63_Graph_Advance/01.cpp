/*
SHORTEST PATH IN UNDIRECTED GRAPH (UNIT WEIGHT)

Given an undirected graph with N vertices and M edges,
find the shortest distance from source node to all other nodes.

All edges have weight = 1.

Example:
N = 5
Edges:
0-1
0-2
1-3
2-4

Source = 0

Output:
0 1 1 2 2
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> shortestPath(int N, vector<vector<int>>& edge, int M, int src)
{
    vector<int> adj[N];

    // Create graph
    for (int i = 0; i < M; i++)
    {
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }

    vector<int> dist(N, -1);
    dist[src] = 0;

    queue<pair<int, int>> q;
    q.push({src, 0});

    while (!q.empty())
    {
        int node = q.front().first;
        int step = q.front().second;
        q.pop();

        for (int k = 0; k < adj[node].size(); k++)
        {
            int next = adj[node][k];

            if (dist[next] == -1)
            {
                dist[next] = step + 1;
                q.push({next, step + 1});
            }
        }
    }

    return dist;
}

int main()
{
    int N = 5;
    int M = 4;
    int src = 0;

    vector<vector<int>> edge = {
        {0,1},
        {0,2},
        {1,3},
        {2,4}
    };

    vector<int> ans = shortestPath(N, edge, M, src);

    for (int x : ans)
        cout << x << " ";

    return 0;
}