#include <bits/stdc++.h>
using namespace std;

// tc: n + nlogk (worst case) || n + lognlogk (best case)
// sc: (n+1)/2 + k ~ n + k

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

long long kthLargestLevelSum(TreeNode *root, int k)
{
    queue<TreeNode *> q;
    q.push(root);
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    while (!q.empty())
    {
        int sz = q.size();
        long long sum = 0;
        for (int i = 0; i < sz; i++)
        {
            TreeNode *top = q.front();
            q.pop();
            sum += top->val;
            if (top->left)
            {
                q.push(top->left);
            }
            if (top->right)
            {
                q.push(top->right);
            }
        }
        pq.push(sum);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    if (pq.size() < k)
        return -1;

    return pq.top();
}

int main()
{
    return 0;
}