/*
KOSARAJU ALGORITHM

Given a directed graph with V vertices,
find the number of Strongly Connected Components (SCC).

SCC:
A component where every vertex can reach every other vertex.

Steps:
1. DFS and store nodes in stack by finish time
2. Reverse all edges (transpose graph)
3. Pop from stack and DFS on transpose graph
4. Count number of DFS calls
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS(int node, vector<vector<int>>& adj, stack<int>& s, vector<bool>& visited)
{
    visited[node] = true;

    for (int i = 0; i < adj[node].size(); i++)
    {
        int next = adj[node][i];

        if (!visited[next])
            DFS(next, adj, s, visited);
    }

    s.push(node);
}

void SCC(int node, vector<bool>& visited, vector<vector<int>>& adj)
{
    visited[node] = true;

    for (int i = 0; i < adj[node].size(); i++)
    {
        int next = adj[node][i];

        if (!visited[next])
            SCC(next, visited, adj);
    }
}

int kosaraju(int V, vector<vector<int>>& adj)
{
    stack<int> s;
    vector<bool> visited(V, false);

    // Step 1
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            DFS(i, adj, s, visited);
    }

    // Step 2: Transpose graph
    vector<vector<int>> trans(V);

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            trans[adj[i][j]].push_back(i);
        }
    }

    // Step 3
    for (int i = 0; i < V; i++)
        visited[i] = false;

    int count = 0;

    while (!s.empty())
    {
        int node = s.top();
        s.pop();

        if (!visited[node])
        {
            count++;
            SCC(node, visited, trans);
        }
    }

    return count;
}

int main()
{
    int V = 5;
    vector<vector<int>> adj(V);

    adj[0].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(3);
    adj[3].push_back(4);

    cout << kosaraju(V, adj);

    return 0;
}