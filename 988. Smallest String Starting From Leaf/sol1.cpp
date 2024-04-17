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

void solve(TreeNode *root, string &s, string &smallestString)
{
    if (!root)
        return;

    s.push_back(char(97 + root->val));

    if (!root->left && !root->right)
    {
        string str = s;
        reverse(str.begin(), str.end());
        if (smallestString.empty())
            smallestString = str;
        else
            smallestString = min(str, smallestString);
    }

    solve(root->left, s, smallestString);
    solve(root->right, s, smallestString);
    s.pop_back();
}

string smallestFromLeaf(TreeNode *root)
{
    string smallestString = "";
    string str = "";
    solve(root, str, smallestString);
    return smallestString;
}

int main()
{
    string s1 = "ababz";
    string s2 = "abz";
    cout << min(s1, s2);
    return 0;
}