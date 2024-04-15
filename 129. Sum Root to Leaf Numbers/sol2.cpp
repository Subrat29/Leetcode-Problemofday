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

void solve(TreeNode *root, vector<int> &digit, vector<vector<int>> &digits)
{
    if (!root)
        return;

    digit.push_back(root->val);
    if (!root->left && !root->right)
        digits.push_back(digit);

    solve(root->left, digit, digits);
    solve(root->right, digit, digits);
    digit.pop_back();
}

int sumNumbers(TreeNode *root)
{
    vector<int> digit;
    vector<vector<int>> digits;
    solve(root, digit, digits);

    for (auto &&digit : digits)
    {
        for (auto &&i : digit)
            cout << i;
        cout << endl;
    }

    int sum = 0;
    for (int i = 0; i < digits.size(); i++)
    {
        long long unsigned int place = 1;
        long long unsigned int num = 0;
        for (int j = digits[i].size() - 1; j >= 0; j--)
        {
            num += digits[i][j] * place;
            place *= 10;
        }
        sum += num;
    }
    return sum;
}

int main()
{
    return 0;
}