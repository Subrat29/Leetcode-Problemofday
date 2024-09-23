#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n + m) where m is the number of words in the dictionary

vector<int> dp;

int solve(int i, int n, string s, unordered_set<string> &st)
{
    if (i >= n)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    // Taking i as an extra character
    int result = 1 + solve(i + 1, n, s, st);

    // Checking for valid substrings
    for (int j = i; j < n; j++)
    {
        string curr = s.substr(i, j - i + 1);
        if (st.find(curr) != st.end())
        {
            // Valid substring found, we can consider it
            result = min(result, solve(j + 1, n, s, st));
        }
    }
    return dp[i] = result; // Store result in dp array
}

int minExtraChar(string s, vector<string> &dict)
{
    dp.resize(s.length(), -1); // Initialize dp with size equal to length of s
    unordered_set<string> st(dict.begin(), dict.end()); // Convert dict to a set for fast lookups

    return solve(0, s.length(), s, st);
}

int main()
{
    // Example usage can be added here
    return 0;
}
