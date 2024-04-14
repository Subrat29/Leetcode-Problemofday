#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void solve(TreeNode *root, int &sum)
{
    if (!root)
        return;

    if (root->left && !root->left->left && !root->left->right)
        sum += root->left->val;

    solve(root->left, sum);
    solve(root->right, sum);
}

int sumOfLeftLeaves(TreeNode *root)
{
    int sum = 0;
    solve(root, sum);
    return sum;
}

int main()
{
    return 0;
}