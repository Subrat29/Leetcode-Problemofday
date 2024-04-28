#include <bits/stdc++.h>
using namespace std;
using vv = vector<vector<int>>;
using v = vector<int>;

void dfs(int node, int parent, v &count, v &res, vv &adj)
{
    for (auto &&child : adj[node])
    {
        if (child == parent)
            continue;
        dfs(child, node, count, res, adj);
        count[node] += count[child];
        res[node] += res[child] + count[child];
    }
    count[node] += 1;
}

void dfs(int node, int parent, v &count, v &res, vv &adj, int n)
{
    for (auto &&child : adj[node])
    {
        if (child == parent)
            continue;
        res[child] = res[node] - count[child] + n - count[child];
        dfs2(child, node, count, res, adj, n);
    }
}

vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
{
    vv adj(n);
    for (auto &&edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    v count(n, 0);
    v res(n, 0);
    dfs(0, -1, count, res, adj);
    dfs2(0, -1, count, res, adj, n);
    return res;
}

int main()
{
    return 0;
}