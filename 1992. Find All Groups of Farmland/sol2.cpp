#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void dfs(vector<vector<int>> &land, int i, int j, int &k, int &l)
{
    if (i < 0 || j < 0 || i >= land.size() || j >= land[0].size() || land[i][j] != 1)
        return;

    land[i][j] = 2;
    if (i > k)
        k = i;
    if (j > l)
        l = j;

    dfs(land, i + 1, j, k, l);
    dfs(land, i, j + 1, k, l);
    dfs(land, i - 1, j, k, l);
    dfs(land, i, j - 1, k, l);
}

vector<vector<int>> findFarmland(vector<vector<int>> &land)
{
    vector<vector<int>> ans;
    for (int i = 0; i < land.size(); i++)
    {
        for (int j = 0; j < land[0].size(); j++)
        {
            if (land[i][j] == 1)
            {
                vector<int> farmLand;
                farmLand.push_back(i);
                farmLand.push_back(j);
                int k = i, l = j;
                dfs(land, i, j, k, l);
                farmLand.push_back(k);
                farmLand.push_back(l);
                ans.push_back(farmLand);
            }
        }
    }
    return ans;
}

int main()
{
    return 0;
}