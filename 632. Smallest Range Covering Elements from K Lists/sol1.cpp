#include <bits/stdc++.h>
using namespace std;

// tc: n * totalNoOfElem
// sc: n

vector<int> smallestRange(vector<vector<int>> &nums)
{
    int n = nums.size();
    vector<int> resultRange = {-1000000, 1000000};
    vector<int> list(n, 0);

    while (true)
    {
        int minElem = INT_MAX;
        int maxElem = INT_MIN;
        int minElemListIdx = 0;

        for (int i = 0; i < n; i++)
        {
            int listIdx = i;
            int elemIdx = list[i];
            int element = nums[listIdx][elemIdx];

            if (element < minElem)
            {
                minElem = element;
                minElemListIdx = listIdx;
            }
            maxElem = max(maxElem, element);
        }

        // range
        if (maxElem - minElem < resultRange[1] - resultRange[0])
        {
            resultRange[0] = minElem;
            resultRange[1] = maxElem;
        }

        // now short the minElemIdx range
        int nextMinElemIdx = list[minElemListIdx] + 1;
        if (nextMinElemIdx >= nums[minElemListIdx].size())
        {
            break;
        }
        list[minElemListIdx] = nextMinElemIdx;
    }
    return resultRange;
}

int main()
{
    return 0;
}