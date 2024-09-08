#include <bits/stdc++.h>
using namespace std;

// tc: n*h
// sc: h

bool solve(ListNode *head, TreeNode *root)
{
    if (head == nullptr)
        return true;
    if (root == nullptr)
        return false;
    if (head->val != root->val)
        return false;

    bool left = solve(head->next, root->left);
    bool right = solve(head->next, root->right);
    return left || right;
}

bool isSubPath(ListNode *head, TreeNode *root)
{
    if (head == nullptr)
        return true;
    if (root == nullptr)
        return false;

    bool left = isSubPath(head, root->left);
    bool right = isSubPath(head, root->right);
    return solve(head, root) || left || right;
}

int main()
{
    return 0;
}