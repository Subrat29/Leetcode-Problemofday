#include <bits/stdc++.h>
using namespace std;

// tc: nlogn
// sc: n

int minGroups(vector<vector<int>> &intervals)
{
    // step1: sort the intervals array acc to start times
    sort(intervals.begin(), intervals.end());

    // step2: create a minHeap whose top elem is always interval whose end time is lowest
    priority_queue<int, vector<int>, greater<int>> pq;
    // step3: traverse the intervals array & do processing
    for (auto &&interval : intervals)
    {
        int start = interval[0], end = interval[1];
        if (!pq.empty() && pq.top() < start)
            pq.pop();
        pq.push(end);
    }
    return pq.size();
}

int main()
{
    return 0;
}