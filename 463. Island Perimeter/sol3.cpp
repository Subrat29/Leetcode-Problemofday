#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// You dont need neighbors and additional calculation.Just simply add 4 when grid[i][j] == 1 then subtract - 2 when you find out there is down or right island.just like this :

class Solution
{
public
    int islandPerimeter(int[][] grid)
    {
        int island = 0;
        for (int i = 0; i <= grid.length - 1; i++)
        {
            for (int j = 0; j <= grid[0].length - 1; j++)
            {
                if (grid[i][j] == 1)
                {
                    island += 4;
                    if (i < grid.length - 1 && grid[i + 1][j] == 1)
                        island = island - 2;
                    if (j < grid[0].length - 1 && grid[i][j + 1] == 1)
                        island = island - 2;
                }
            }
        }
        return island;
    }
}

int
main()
{
    return 0;
}