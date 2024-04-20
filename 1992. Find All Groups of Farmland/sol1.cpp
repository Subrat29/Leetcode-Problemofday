#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// tle
bool isValid(vector<vector<int>> &land, int i, int j)
{
    if (i < 0 || j < 0 || i >= land.size() || j >= land[0].size() || land[i][j] != 1)
        return false;
    else
        return true;
}

void bfs(vector<vector<int>> &land, int i, int j, vector<int> &farmLand)
{
    farmLand.push_back(i);
    farmLand.push_back(j);

    queue<pair<int, int>> q;
    q.push({i, j});
    int x = 0, y = 0;

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        land[x][y] = 2;

        if ((isValid(land, x + 1, y)))
            q.push({x + 1, y});
        if ((isValid(land, x, y + 1)))
            q.push({x, y + 1});
        if ((isValid(land, x - 1, y)))
            q.push({x - 1, y});
        if ((isValid(land, x, y - 1)))
            q.push({x, y - 1});
    }
    farmLand.push_back(x);
    farmLand.push_back(y);
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
                bfs(land, i, j, farmLand);
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