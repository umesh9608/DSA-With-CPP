/*
---------------------------------------------------------
4. PRIM'S ALGORITHM (MINIMUM SPANNING TREE)
---------------------------------------------------------

Notes:
- Used to find Minimum Spanning Tree (MST)
- Greedy Algorithm
- Uses Min Heap
- Select minimum weight edge every time

Time Complexity:
O(E logV)
*/


// int primMST(int V, vector<pair<int,int> > adj[])
// {
//     priority_queue<pair<int,int>,
//                    vector<pair<int,int> >,
//                    greater<pair<int,int> > > pq;

//     vector<bool> visited(V, false);

//     pq.push(make_pair(0, 0));
//     int sum = 0;

//     while (!pq.empty())
//     {
//         int weight = pq.top().first;
//         int node = pq.top().second;
//         pq.pop();

//         if (visited[node])
//             continue;

//         visited[node] = true;
//         sum += weight;

//         for (auto it : adj[node])
//         {
//             int next = it.first;
//             int wt = it.second;

//             if (!visited[next])
//                 pq.push(make_pair(wt, next));
//         }
//     }

//     return sum;
// }

// /*
// ---------------------------------------------------------
// 5. KRUSKAL ALGORITHM (MINIMUM SPANNING TREE)
// ---------------------------------------------------------

// Notes:
// - Sort edges by weight
// - Pick smallest edge first
// - Use Disjoint Set (Union Find)
// - Avoid cycle

// Time Complexity:
// O(E logE)
// */

// vector<int> parent;

// int findParent(int node)
// {
//     if (parent[node] == node)
//         return node;

//     return parent[node] = findParent(parent[node]);
// }

// void unionSet(int u, int v)
// {
//     u = findParent(u);
//     v = findParent(v);

//     if (u != v)
//         parent[u] = v;
// }

// void kruskalMST()
// {
//     int V = 4;

//     vector<vector<int> > edges;
//     edges.push_back({1,0,1});
//     edges.push_back({3,1,2});
//     edges.push_back({2,0,3});
//     edges.push_back({4,2,3});

//     sort(edges.begin(), edges.end());

//     parent.resize(V);
//     for (int i = 0; i < V; i++)
//         parent[i] = i;

//     int mstWeight = 0;

//     for (auto edge : edges)
//     {
//         int wt = edge[0];
//         int u = edge[1];
//         int v = edge[2];

//         if (findParent(u) != findParent(v))
//         {
//             mstWeight += wt;
//             unionSet(u, v);
//         }
//     }

//     cout << "\nKruskal MST Weight = " << mstWeight << endl;
// }

// /*
// ---------------------------------------------------------
// MAIN FUNCTION
// ---------------------------------------------------------
// */

// int main()
// {
//     // BFS Example
//     int V1 = 5;
//     vector<int> adj1[V1];

//     adj1[0].push_back(1);
//     adj1[0].push_back(2);
//     adj1[1].push_back(3);
//     adj1[2].push_back(4);

//     shortestPathBFS(V1, adj1, 0);

//     // Dijkstra Example
//     int V2 = 3;
//     vector<pair<int,int> > adj2[V2];

//     adj2[0].push_back({1,4});
//     adj2[0].push_back({2,1});
//     adj2[2].push_back({1,2});

//     vector<int> ans = dijkstra(V2, adj2, 0);

//     cout << "\nDijkstra Distance:\n";
//     for (int x : ans)
//         cout << x << " ";

//     cout << endl;

//     // Bellman Ford
//     bellmanFord();

//     // Prim Example
//     int V3 = 3;
//     vector<pair<int,int> > adj3[V3];

//     adj3[0].push_back({1,5});
//     adj3[1].push_back({0,5});

//     adj3[1].push_back({2,3});
//     adj3[2].push_back({1,3});

//     adj3[0].push_back({2,1});
//     adj3[2].push_back({0,1});

//     cout << "\nPrim MST Weight = " << primMST(V3, adj3) << endl;

//     // Kruskal
//     kruskalMST();

//     return 0;
// }
