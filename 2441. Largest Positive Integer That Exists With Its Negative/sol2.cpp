#include <bits/stdc++.h>
using namespace std;

int findMaxK(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = n - 1; i >= 0 && nums[i] > 0; i--)
    {
        for (int j = 0; j < n && -nums[j] >= nums[i]; j++)
        {
            if (nums[i] + nums[j] == 0)
                return nums[i];
        }
    }
    return -1;
}

int main()
{
    return 0;
}