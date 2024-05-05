#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// tc: n, sc: 1

void deleteNode(ListNode *node)
{
    ListNode *temp = node;
    while (node->next)
    {
        node->val = node->next->val;
        temp = node;
        node = node->next;
    }
    temp->next = NULL;
}

int main()
{
    return 0;
}