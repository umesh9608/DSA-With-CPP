/*
DETECT CYCLE IN AN UNDIRECTED GRAPH

Given an undirected graph with V vertices and edges,
check whether it contains a cycle or not.

Graph is represented using adjacency list.

Example:
Input:
V = 5, E = 5

Adj = {
    {1},
    {0,2,4},
    {1,3},
    {2,4},
    {1,3}
}

Output:
1

Explanation:
Cycle exists in graph.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool BFS(int node, vector<int> adj[], vector<bool>& visit)
    {
        queue<pair<int, int>> q;
        q.push({node, -1});
        visit[node] = true;

        while (!q.empty())
        {
            int child = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int i = 0; i < adj[child].size(); i++)
            {
                int neighbor = adj[child][i];

                if (!visit[neighbor])
                {
                    visit[neighbor] = true;
                    q.push({neighbor, child});
                }
                else if (neighbor != parent)
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> visit(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visit[i])
            {
                if (BFS(i, adj, visit))
                    return true;
            }
        }

        return false;
    }
};

int main()
{
    int V = 5;
    vector<int> adj[V];

    adj[0].push_back(1);

    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[1].push_back(4);

    adj[2].push_back(1);
    adj[2].push_back(3);

    adj[3].push_back(2);
    adj[3].push_back(4);

    adj[4].push_back(1);
    adj[4].push_back(3);

    Solution obj;

    if (obj.isCycle(V, adj))
        cout << 1;
    else
        cout << 0;

    return 0;
}