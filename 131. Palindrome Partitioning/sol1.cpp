#include <bits/stdc++.h>
using namespace std;

// sc: n*2^n
// tc: n*2^n

bool isPalindrome(string s, int start, int end)
{
    while (start < end)
    {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}

void solve(string s, int idx, vector<string> &path, vector<vector<string>> &res)
{
    if (idx == s.size())
    {
        res.push_back(path);
        return;
    }

    for (int i = idx; i < s.size(); i++)
    {
        if (isPalindrome(s, idx, i))
        {
            path.push_back(s.substr(idx, i - idx + 1));
            solve(s, i + 1, path, res);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> res;
    vector<string> path;
    solve(s, 0, path, res);
    return res;
}

int main()
{
    return 0;
}