#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int trap(vector<int> &height)
{
    int left = 0;
    int right = height.size() - 1;
    int maxLeft = 0;
    int maxRight = 0;

    int totalWater = 0;
    while (left < right)
    {
        if (height[left] < height[right])
        {
            if (height[left] >= maxLeft)
                maxLeft = height[left];
            else
                totalWater += maxLeft - height[left];
            left++;
        }
        else
        {
            if (height[right] >= maxRight)
                maxRight = height[right];
            else
                totalWater += maxRight - height[right];
            right--;
        }
    }
    return totalWater;
}

int main()
{
    return 0;
}