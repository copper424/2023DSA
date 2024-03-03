#include "ListNode.h"

ListNode* h;

bool dfs(ListNode* curr)
{
    if (curr)
    {
        // 递归到下一个结点，如果已经返回失败，那必然不会回文，直接返回失败即可
        if (!dfs(curr->next))
        {
            return false;
        }
        // 判断头和尾是否一样
        if (h->val != curr->val)
        {
            return false;
        }
        // 一样情况，头结点走到下一个结点
        h = h->next;
    }
    // 对于空的情况也返回true
    return true;
}

bool isPalindrome(ListNode* head) {
    h = head;
    return dfs(head);
}
