#include <bits/stdc++.h>
using namespace std;

int countSteps(int ringIdx, int i, int ringLen)
{
    int distance = abs(i - ringIdx);
    int wrapAroundDistance = ringLen - distance;
    return min(distance, wrapAroundDistance);
}

int solve(int ringIdx, int keyIdx, string &ring, string &key, vector<vector<int>> &dp)
{
    if (keyIdx == key.length())
        return 0;

    if (dp[ringIdx][keyIdx] != -1)
        return dp[ringIdx][keyIdx];

    int ans = INT_MAX;
    for (int i = 0; i < ring.length(); i++)
    {
        if (ring[i] == key[keyIdx])
        {
            int steps = 1 + countSteps(ringIdx, i, ring.length());
            int totalSteps = steps + solve(i, keyIdx + 1, ring, key, dp);
            ans = min(ans, totalSteps);
        }
    }
    dp[ringIdx][keyIdx] = ans;
    return dp[ringIdx][keyIdx];
}

int findRotateSteps(string ring, string key)
{
    vector<vector<int>> dp(ring.size() + 1, vector<int>(key.size() + 1, -1));
    return solve(0, 0, ring, key, dp);
}

int main()
{
    return 0;
}