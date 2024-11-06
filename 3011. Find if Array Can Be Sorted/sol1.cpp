#include <bits/stdc++.h>
using namespace std;

// tc: nlogn
// sc: n

bool canSortArray(vector<int> &nums)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;
    int n = nums.size();
    int i = 0;
    while (i < n)
    {
        int countSetBits = __builtin_popcount(nums[i]);
        while (i < n && countSetBits == __builtin_popcount(nums[i]))
        {
            pq.push(nums[i]);
            i++;
        }
        while (!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
    }
    sort(nums.begin(), nums.end());

    // for (auto &&i : v){}

    return ans == nums;
}

int main()
{
    return 0;
}