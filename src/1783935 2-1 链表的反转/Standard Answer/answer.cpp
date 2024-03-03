#include"ListNode.h" 

ListNode *reverseList(ListNode *head)
{
    auto res = head;
    head = head->next;

    ListNode *pre = nullptr, *next = nullptr;
    while (head)
    {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }

    res->next = pre;
    return res;
}
