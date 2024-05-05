#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// tc: 1, sc: 1

void deleteNode(ListNode *node)
{
    node->val = node->next->val;
    node->next = node->next->next;
}

int main()
{
    return 0;
}