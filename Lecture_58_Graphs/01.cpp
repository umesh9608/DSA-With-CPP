/*
NUMBER OF PROVINCES

Given an adjacency matrix of a graph where adj[i][j] = 1
means city i is directly connected to city j.

Find the number of provinces (connected components).

Example:
Input:
3
1 1 0
1 1 0
0 0 1

Output:
2

Explanation:
{0,1} is one province
{2} is another province
*/

#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>>& adj, vector<bool>& visit, int node)
{
    if (visit[node])
        return;

    visit[node] = true;

    for (int i = 0; i < adj[node].size(); i++)
    {
        if (adj[node][i] == 1 && !visit[i])
            DFS(adj, visit, i);
    }
}

int numProvinces(vector<vector<int>>& adj, int v)
{
    int count = 0;
    vector<bool> visit(v, false);

    for (int i = 0; i < v; i++)
    {
        if (!visit[i])
        {
            count++;
            DFS(adj, visit, i);
        }
    }

    return count;
}

int main()
{
    int v;
    cin >> v;

    vector<vector<int>> adj(v, vector<int>(v));

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            cin >> adj[i][j];
    }

    cout << numProvinces(adj, v);

    return 0;
}