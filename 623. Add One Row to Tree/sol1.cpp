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

void solve(TreeNode *root, int val, int targetDepth, int depth)
{
    if (!root)
        return;

    if (depth == targetDepth)
    {
        TreeNode *node1 = new TreeNode(val);
        TreeNode *node2 = new TreeNode(val);

        node1->left = root->left;
        node2->right = root->right;
        root->left = node1;
        root->right = node2;
        return;
    }

    solve(root->left, val, targetDepth, depth + 1);
    solve(root->right, val, targetDepth, depth + 1);
}

TreeNode *addOneRow(TreeNode *root, int val, int depth)
{
    if (depth == 1)
    {
        TreeNode *newRoot = new TreeNode(val);
        newRoot->left = root;
        return newRoot;
    }

    TreeNode *newRoot = root;
    solve(newRoot, val, depth - 1, 1);
    return root;
}

int main()
{
    return 0;
}