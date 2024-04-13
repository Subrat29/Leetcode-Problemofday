#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Remember: In first approach i work on the char matrix which is given in the question but 
// my friend tell me that how you store integer above 9 because 10 is string not char
// then i convert the given matrix in <int> matrix now all set babes :)
int maximalRectangle(vector<vector<char>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> m(row, vector<int>(col, 0));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == '1')
                m[i][j] = 1;
            else
                m[i][j] = 0;
        }
    }

    int maxLen = 0;
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[0].size() && i != 0; j++)
        {
            if (m[i][j] != 0)
            {
                int sum = m[i][j] + m[i - 1][j];
                m[i][j] = sum;
            }
        }

        int maxValue = *max_element(m[i].begin(), m[i].end());

        for (int k = 1; k <= maxValue; k++)
        {
            int len = 0;
            for (int j = 0; j < m[0].size(); j++)
            {
                if (m[i][j] >= k)
                    len++;
                else
                    len = 0;
                maxLen = max(maxLen, k * len);
            }
        }
    }
    return maxLen;
}

int main()
{
    // vector<vector<char>> matrix = {{"3", "1", "3", "2", "2"}};
    // cout << "maxLen: " << maximalRectangle(matrix) << endl;

    return 0;
}