#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool dfs(vector<vector<int>> &adj, vector<int> &vis, int src, int dest)
{
    vis[src] = 1;
    if (src == dest)
        return true;
    for (auto &&i : adj[src])
    {
        if (!vis[i])
        {
            if (dfs(adj, vis, i, dest))
                return true;
        }
    }
    return false;
}

bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    vector<vector<int>> adj(n);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n, 0);
    return dfs(adj, vis, source, destination);
}

int main()
{
    return 0;
}