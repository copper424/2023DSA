#ifndef ListNode_h
#define ListNode_h

struct ListNode {
    int val;
    ListNode *next = nullptr;
    ListNode(int x) : val(x){}
};

#endif