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

    v ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        v count(n, 0);
        v res(n, 0);
        dfs(i, -1, count, res, adj);
        ans[i] = res[i];
    }
    return ans;
}

int main()
{
    return 0;
}