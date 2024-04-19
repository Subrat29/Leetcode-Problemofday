#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool dfs(vector<vector<int>> &grid, int &perimeter, int i, int j)
{
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
        return false;
    else if (grid[i][j] == 2)
        return true;

    grid[i][j] = 2;
    int peri = 0;
    if (!dfs(grid, perimeter, i + 1, j))
        peri++;
    cout << "[" << i << j << "] -> "
         << "peri: " << peri << endl;

    if (!dfs(grid, perimeter, i, j + 1))
        peri++;
    cout << "[" << i << j << "] -> "
         << "peri: " << peri << endl;

    if (!dfs(grid, perimeter, i - 1, j))
        peri++;
    cout << "[" << i << j << "] -> "
         << "peri: " << peri << endl;

    if (!dfs(grid, perimeter, i, j - 1))
        peri++;

    cout << "[" << i << j << "] -> "
         << "peri: " << peri << endl;
    perimeter += peri;
    cout << perimeter << endl;
    return true;
}

int islandPerimeter(vector<vector<int>> &grid)
{
    int perimeter = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (dfs(grid, perimeter, i, j))
                break;
        }
    }
    return perimeter;
}
int main()
{
    return 0;
}