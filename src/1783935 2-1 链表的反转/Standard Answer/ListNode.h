#ifndef ListNode_h
#define ListNode_h

struct ListNode
{
    int val;
    ListNode *next = nullptr;
    ListNode(int n=0) : val(n) {}
};

ListNode *reverseList(ListNode *);

#endif
