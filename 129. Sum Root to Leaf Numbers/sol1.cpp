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

void solve(TreeNode *root, string &digit, vector<string> &digits)
{
    if (!root)
        return;

    digit += to_string(root->val);
    if (!root->left && !root->right)
        digits.push_back(digit);

    solve(root->left, digit, digits);
    solve(root->right, digit, digits);
    digit.pop_back();
}

int sumNumbers(TreeNode *root)
{
    string digit = "";
    vector<string> digits;
    solve(root, digit, digits);

    int sum = 0;
    for (auto &&digit : digits)
    {
        int num = stoi(digit);
        sum += num;
    }
    return sum;
}

int main()
{
    return 0;
}