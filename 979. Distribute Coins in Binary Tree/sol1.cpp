#include <bits/stdc++.h>
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

// sc: h
// tc: n

int solve(TreeNode *root, TreeNode *parent)
{
    if (!root)
        return 0;
        
    int moves = solve(root->left, root) + solve(root->right, root);
    int coins = root->val - 1;
    if (parent)
        parent->val += coins;
    moves += abs(coins);
    return moves;
}

int distributeCoins(TreeNode *root)
{
    return solve(root, nullptr);
}

int main()
{
    return 0;
}