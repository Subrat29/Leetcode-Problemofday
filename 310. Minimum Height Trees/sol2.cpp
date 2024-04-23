#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
{
    if (n == 0)
        return {};
    if (n == 1)
        return {0};

    vector<vector<int>> adj(n);
    vector<int> degree(n, 0);

    // create adj list & indegree list
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    // push the leaf node to queue and mark them visited (no need)
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (degree[i] == 1)
            q.push(i);
    }

    // do processing
    vector<int> ans;
    while (!q.empty())
    {
        ans.clear();
        int size = q.size();
        while (size--)
        {
            int front = q.front();
            ans.push_back(front);
            q.pop();

            for (auto &&nbr : adj[front])
            {
                degree[nbr]--;
                if (degree[nbr] == 1)
                    q.push(nbr);
            }
        }
    }
    return ans;
}

int main()
{
    int n = 6;
    vector<vector<int>> edges = {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
    vector<int> ans = findMinHeightTrees(n, edges);
    cout << "Ans: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ", ";
    }

    return 0;
}