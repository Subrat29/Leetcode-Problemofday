#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int trap(vector<int> &height)
{
    int n = height.size();
    vector<int> maxLeftHeight(n, 0);
    vector<int> maxRightHeight(n, 0);

    int maxLeftHt = height[0], maxRightHt = height[n - 1];
    for (int i = 1; i < n; i++)
    {
        maxLeftHeight[i] = maxLeftHt;
        if (height[i] > maxLeftHt)
            maxLeftHt = height[i];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        maxRightHeight[i] = maxRightHt;
        if (height[i] > maxRightHt)
            maxRightHt = height[i];
    }

    int trapWater = 0;
    for (int i = 0; i < n; i++)
    {
        int water = min(maxLeftHeight[i], maxRightHeight[i]) - height[i];
        if (water > 0)
            trapWater += water;
    }
    return trapWater;
}

int main()
{
    return 0;
}