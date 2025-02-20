#include <bits/stdc++.h>
using namespace std;

// tc: 2*2*2*2...n => 2^n  = n*2^n
// sc: n

class Solution
{
public:
    vector<char> v = {'0', '1'};

    void solve(int n, string &s, string &ans, vector<string> &nums)
    {
        if (n == 0)
        {
            bool isDiff = true;
            for (int i = 0; i < nums.size(); i++)
            {
                if (s == nums[i])
                {
                    isDiff = false;
                    break;
                }
            }
            if (isDiff)
            {
                ans = s;
            }
            return;
        }

        for (int i = 0; i <= 1; i++)
        {
            if (ans.empty())
            {
                s.push_back(v[i]);
                solve(n - 1, s, ans, nums);
                s.pop_back();
            }
        }
    }

    string findDifferentBinaryString(vector<string> &nums)
    {
        int n = nums.size();
        string ans = "", s = "";
        solve(n, s, ans, nums);
        return ans;
    }
};

int main()
{
    return 0;
}