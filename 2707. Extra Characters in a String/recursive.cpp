#include <bits/stdc++.h>
using namespace std;

// tc:
// sc:

int solve(int i, int n, string s, unordered_set<string> &st)
{
    if (i >= n)
        return 0;

    // taking i as a extra character
    int result = 1 + solve(i + 1, n, s, st);

    // taking i as not a extra character
    for (int j = i; j < n; j++)
    {
        string curr = s.substr(i, j - i + 1);
        if (st.find(curr) != st.end())
        {
            // valid substring
            result = min(result, solve(j + 1, n, s, st));
        }
    }
    return result;
}

int minExtraChar(string s, vector<string> &dict)
{
    unordered_set<string> st(dict.begin(), dict.end());

    return solve(0, s.length(), s, st);
}

int main()
{
    return 0;
}