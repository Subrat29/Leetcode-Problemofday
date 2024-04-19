#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TLE
bool isValid(int x, int y, vector<vector<char>> &grid)
{
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != '1')
        return false;
    else
        return true;
}

void bfs(vector<vector<char>> &grid, int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        grid[x][y] = '2';

        if (isValid(x + 1, y, grid))
            q.push({x + 1, y});
        if (isValid(x, y + 1, grid))
            q.push({x, y + 1});
        if (isValid(x - 1, y, grid))
            q.push({x - 1, y});
        if (isValid(x, y - 1, grid))
            q.push({x, y - 1});
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int island = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == '1')
            {
                island++;
                bfs(grid, i, j);
            }
        }
    }
    return island;
}

int main()
{
    return 0;
}