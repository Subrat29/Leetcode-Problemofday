#include <bits/stdc++.h>
using namespace std;

int findMaxK(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int low = 0;
    int high = nums.size() - 1;
    while (low < high)
    {
        if (-nums[low] == nums[high])
            return nums[high];
        else if (-nums[low] > nums[high])
            low++;
        else
            high--;
    }
    return -1;
}

int main()
{
    return 0;
}