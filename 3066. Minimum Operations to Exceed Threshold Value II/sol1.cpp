#include <bits/stdc++.h>
using namespace std;

// tc: nlogn
// sc: n

int minOperations(vector<int> &nums, int k)
{
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    for (auto i : nums)
    {
        minHeap.push(i);
    }

    int cnt = 0;
    while (minHeap.size() >= 2 && minHeap.top() < k)
    {
        long long x = minHeap.top();
        minHeap.pop();
        long long y = minHeap.top();
        minHeap.pop();
        long long calculated_value = min(x, y) * 2 + max(x, y);
        minHeap.push(calculated_value);
        cnt++;
    }
    return cnt;
}

int main()
{
    return 0;
}