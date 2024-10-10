#include <bits/stdc++.h>
using namespace std;

// tc: 2^n
// sc: 1

int solve(int i, int j, vector<int> &nums)
{
    if (i >= nums.size() || j < 0)
        return 0;

    if (nums[i] <= nums[j])
        return j - i;

    return max(solve(i + 1, j, nums), solve(i, j - 1, nums));
}

int maxWidthRamp(vector<int> &nums)
{
    int i = 0;
    int j = nums.size() - 1;

    return solve(i, j, nums);
}

int main()
{
    return 0;
}