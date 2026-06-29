/*
=========================================================
LECTURE: SHORTEST DISTANCE AND SPANNING TREE
=========================================================

Topics Covered:
1. Shortest Path in Unweighted Graph (BFS)
2. Dijkstra Algorithm
3. Bellman-Ford Algorithm
4. Prim's Algorithm (MST)
5. Kruskal Algorithm (MST)

---------------------------------------------------------
1. SHORTEST PATH IN UNWEIGHTED GRAPH (BFS)
---------------------------------------------------------

Notes:
- Used when all edges have equal weight (usually weight = 1)
- BFS guarantees shortest path
- Uses Queue

Time Complexity:
O(V + E)
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void shortestPathBFS(int V, vector<int> adj[], int src)
{
    vector<int> dist(V, -1);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int i = 0; i < adj[node].size(); i++)
        {
            int next = adj[node][i];

            if (dist[next] == -1)
            {
                dist[next] = dist[node] + 1;
                q.push(next);
            }
        }
    }

    cout << "Shortest Distance from Source:\n";
    for (int i = 0; i < V; i++)
        cout << i << " -> " << dist[i] << endl;
}

/*
---------------------------------------------------------
2. DIJKSTRA ALGORITHM
---------------------------------------------------------

Notes:
- Finds shortest path from source
- Works only for positive weights
- Uses Min Heap (Priority Queue)

Time Complexity:
O((V+E) logV)
*/

#include<queue>

vector<int> dijkstra(int V, vector<pair<int,int> > adj[], int src)
{
    priority_queue<pair<int,int>,
                   vector<pair<int,int> >,
                   greater<pair<int,int> > > pq;

    vector<int> dist(V, 1e9);

    dist[src] = 0;
    pq.push(make_pair(0, src));

    while (!pq.empty())
    {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int weight = it.second;

            if (distance + weight < dist[adjNode])
            {
                dist[adjNode] = distance + weight;
                pq.push(make_pair(dist[adjNode], adjNode));
            }
        }
    }

    return dist;
}

/*
---------------------------------------------------------
3. BELLMAN FORD ALGORITHM
---------------------------------------------------------

Notes:
- Works with negative weights
- Can detect negative cycle
- Relax all edges V-1 times

Time Complexity:
O(V * E)
*/

void bellmanFord()
{
    int V = 5;

    vector<vector<int> > edges;
    edges.push_back({0,1,5});
    edges.push_back({1,2,-2});
    edges.push_back({2,3,3});
    edges.push_back({3,4,1});

    vector<int> dist(V, 1e9);
    dist[0] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (dist[u] != 1e9 && dist[u] + wt < dist[v])
                dist[v] = dist[u] + wt;
        }
    }

    cout << "\nBellman Ford Distance:\n";
    for (int x : dist)
        cout << x << " ";
}