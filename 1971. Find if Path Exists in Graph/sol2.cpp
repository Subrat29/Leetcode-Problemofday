#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Union Find
int findParent(int node, vector<int> &parent)
{
    if (parent[node] == node)
        return node;
    else
        return parent[node] = findParent(parent[node], parent);
}

void unionOfNodes(int u, int v, vector<int> &parent)
{
    int uParent = findParent(u, parent);
    int vParent = findParent(v, parent);
    parent[uParent] = vParent;
}

bool validPath(int n, vector<vector<int>> &edges, int start, int end)
{
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (auto &&edge : edges)
    {
        unionOfNodes(edge[0], edge[1], parent);
    }
    return findParent(start, parent) == findParent(end, parent);
}

int main()
{
    return 0;
}