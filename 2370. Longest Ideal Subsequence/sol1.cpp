#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(string &s, int index, int prev, int &k, vector<vector<int>> &dp)
{
    if (index >= s.size())
        return 0;

    if (dp[index][prev] != -1)
        return dp[index][prev];

    int inc = 0, notinc = 0;
    if (prev == 0 || abs(s[index] - prev) <= k)
    {
        inc = 1 + solve(s, index + 1, s[index], k, dp);
    }
    notinc = solve(s, index + 1, prev, k, dp);

    return dp[index][prev] = max(inc, notinc);
}

int longestIdealString(string s, int k)
{
    vector<vector<int>> dp(s.size() + 1, vector<int>(150, -1));
    return solve(s, 0, 0, k, dp);
}

int main()
{
    string s = "acfgbd";
    int k = 2;
    int ans = longestIdealString(s, k);
    cout << "Ans: " << ans << endl;
    return 0;
}