#include "ListNode.h"

ListNode *partList(ListNode *head, int x)
{
    ListNode *leftHead = nullptr, *rightHead = nullptr, *left = nullptr, *right = nullptr;

    while (head != nullptr)
    {
        if (head->val < x)
        {
            if (leftHead)
            {
                left->next = head;
                left = left->next;
            }
            else
            {
                left = leftHead = head;
            }
        }
        else
        {
            if (rightHead)
            {
                right->next = head;
                right = right->next;
            }
            else
            {
                rightHead = right = head;
            }
        }
        head = head->next;
    }
    right->next = nullptr;
    left->next = rightHead;

    return leftHead;
}
