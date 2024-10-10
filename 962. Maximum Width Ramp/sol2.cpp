#include <bits/stdc++.h>
using namespace std;

// tc: n
// sc: n

int maxWidthRamp(vector<int> &nums)
{
    // Build dec stack of indexes
    stack<int> st;
    for (int i = 0; i < nums.size(); i++)
    {
        if (st.empty() || nums[st.top()] > nums[i]) // agr koi chota aa jaye to push kr do stack ke top se
        {
            st.push(i);
        }
    }

    // traverse from end to find max width ramp
    int maxWidth = 0;

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[st.top()] <= nums[i])
        {
            maxWidth = max(maxWidth, i - st.top());
            st.pop();
        }
    }
    return maxWidth;
}

int main()
{
    return 0;
}