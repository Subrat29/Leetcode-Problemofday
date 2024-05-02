#include <bits/stdc++.h>
using namespace std;

int findMaxK(vector<int> &nums)
{

    sort(nums.begin(), nums.end());
    vector<int> negative, positive;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
            positive.push_back(nums[i]);
        else
            negative.push_back(nums[i]);
    }

    if (positive.size() < 0 || negative.size() < 0)
        return -1;

    for (int i = positive.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < negative.size(); j++)
        {
            if (positive[i] + negative[j] == 0)
                return positive[i];
        }
    }
    return -1;
}

int main()
{
    return 0;
}