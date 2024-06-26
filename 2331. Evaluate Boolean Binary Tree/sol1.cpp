#include <bits/stdc++.h>
using namespace std;

// sc: no. of nodes
// tc: height of tree or n in worst case

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool evaluateTree(TreeNode *root)
{
    if (root->val == 0 || root->val == 1)
        return root->val;

    if (root->val == 2)
        return evaluateTree(root->left) || evaluateTree(root->right);

    return evaluateTree(root->left) && evaluateTree(root->right);
}

int main()
{
    return 0;
}