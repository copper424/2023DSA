#include"ListNode.h"

ListNode* reverseList(ListNode* head){
    ListNode* prev = nullptr;
    ListNode* curr = head->next;
    while(curr != nullptr){
        ListNode* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        
    }
    head = new ListNode;
    head->next = prev;
    return head;
}