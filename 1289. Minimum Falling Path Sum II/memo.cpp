#include <bits/stdc++.h>
using namespace std;

int solve(int row, int prevCol, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (row == grid.size() - 1)
        return grid[row][prevCol];

    if (dp[row][prevCol] != -1)
        return dp[row][prevCol];

    int ans = INT_MAX;
    for (int col = 0; col < grid[0].size(); col++)
    {
        if (col != prevCol)
            ans = min(ans, solve(row + 1, col, grid, dp));
    }
    dp[row][prevCol] = ans + grid[row][prevCol];
    return dp[row][prevCol];
}

int minFallingPathSum(vector<vector<int>> &grid)
{
    int r = grid.size();
    int c = grid[0].size();

    vector<vector<int>> dp(r, vector<int>(c, -1));

    int ans = INT_MAX;
    for (int col = 0; col < grid[0].size(); col++)
    {
        ans = min(ans, solve(0, col, grid, dp));
    }
    return ans;
}

int main()
{
    return 0;
}