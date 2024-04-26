#include <bits/stdc++.h>
using namespace std;

int minFallingPathSum(vector<vector<int>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();

    vector<vector<int>> dp(row, vector<int>(col, -1));

    // directly copy last row
    for (int j = 0; j < col; j++)
        dp[row - 1][j] = grid[row - 1][j];

    int 

    for (int i = row - 2; i >= 0; i--)
    {
        for (int j = col - 1; j >= 0; j--)
        {
            int mini = INT_MAX;
            for (int k = 0; k < col; k++)
            {
                if (k != j)
                    mini = min(mini, dp[i + 1][k]);
            }
            dp[i][j] = mini + grid[i][j];
        }
    }

    int ans = *min_element(dp[0].begin(), dp[0].end());
    return ans;
}

int main()
{
    return 0;
}