#include <bits/stdc++.h>
using namespace std;

// sc: 1
// tc: n

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNodes(ListNode *head)
{
    if (!head->next)
        return head;

    // step1: reversed linked list
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *next = head;

    while (curr)
    {
        next = next->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // step2: delete nodes
    head = prev;
    ListNode *temp = prev->next;
    int high = prev->val;
    while (temp)
    {
        if (temp->val < high)
        {
            prev->next = temp->next;
            temp->next = nullptr;
            temp = prev->next;
        }
        else
        {
            high = temp->val;
            prev = temp;
            temp = temp->next;
        }
    }

    // step3: again reverse the list
    prev = nullptr;
    curr = head;
    next = head;
    while (curr)
    {
        next = next->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main()
{
    return 0;
}