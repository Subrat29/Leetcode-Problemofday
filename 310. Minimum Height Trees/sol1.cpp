#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


// Tle
int bfs(int node, vector<vector<int>> &adj, vector<int> &vis)
{
    int height = 0;
    queue<int> q;
    q.push(node);
    vis[node] = 1;
    while (!q.empty())
    {
        int qSize = q.size();
        while (qSize--)
        {
            int front = q.front();
            q.pop();

            for (auto &&nbr : adj[front])
            {
                if (!vis[nbr])
                {
                    vis[nbr] = 1;
                    q.push(nbr);
                }
            }
        }
        height++;
    }
    return height;
}

vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(n);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        vector<int> vis(n, 0);
        int ht = bfs(i, adj, vis);
        heights[i] = ht;
    }

    int minElement = *min_element(heights.begin(), heights.end());
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (heights[i] == minElement)
            ans.push_back(i);
    }
    return ans;
}

int main()
{
    return 0;
}