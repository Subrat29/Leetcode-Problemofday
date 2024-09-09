#include <bits/stdc++.h>
using namespace std;

// tc: m*n
// sc: m*n

vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
{
    vector<vector<int>> ans(m, vector<int>(n, -1));
    int topRow = 0;
    int bottomRow = m - 1;
    int leftCol = 0;
    int rightCol = n - 1;

    while (head)
    {
        // Fill Top Row
        for (int i = leftCol; i <= rightCol && head; i++)
        {
            ans[topRow][i] = head->val;
            head = head->next;
        }
        topRow++;

        // Fill Right Column
        for (int i = topRow; i <= bottomRow && head; i++)
        {
            ans[i][rightCol] = head->val;
            head = head->next;
        }
        rightCol--;

        // Fill Bottom Row
        for (int i = rightCol; i >= leftCol && head; i--)
        {
            ans[bottomRow][i] = head->val;
            head = head->next;
        }
        bottomRow--;

        // Fill Left Column
        for (int i = bottomRow; i >= topRow && head; i--)
        {
            ans[i][leftCol] = head->val;
            head = head->next;
        }
        leftCol++;
    }
    return ans;
}

int main()
{
    return 0;
}