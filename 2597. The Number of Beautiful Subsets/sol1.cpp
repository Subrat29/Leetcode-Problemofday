#include <bits/stdc++.h>
using namespace std;

// sc: n
// tc: n * 2^n

void solve(int idx, int &cnt, vector<int> &nums, vector<int> &temp, int k)
{
    // base case
    if (idx >= nums.size())
    {
        cnt++;
        return;
    }

    bool isValid = true;
    for (int i = 0; i < temp.size(); i++)
    {
        if (abs(temp[i] - nums[idx]) == k)
        {
            isValid = false;
            break;
        }
    }

    if (isValid)
    {
        // take it
        temp.push_back(nums[idx]);
        solve(idx + 1, cnt, nums, temp, k);
        temp.pop_back();
    }
    // not take it
    solve(idx + 1, cnt, nums, temp, k);
}

int beautifulSubsets(vector<int> &nums, int k)
{
    int cnt = 0;
    vector<int> temp;
    solve(0, cnt, nums, temp, k);
    return cnt - 1;
}

int main()
{
    return 0;
}