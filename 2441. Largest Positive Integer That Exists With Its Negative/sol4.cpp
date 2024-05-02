#include <bits/stdc++.h>
using namespace std;

// Using bitset
int findMaxK(vector<int> &nums)
{
    int ans = -1;
    bitset<2001> seen;

    for (auto &&i : nums)
    {
        if (abs(i) > ans && seen[-i + 1000])
            ans = abs(i);

        seen[i + 1000] = true;
    }
    return ans;
}

int main()
{
    return 0;
}