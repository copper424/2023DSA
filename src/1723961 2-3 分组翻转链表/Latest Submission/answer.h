#include"ListNode.h"

ListNode* reverseKGroup(ListNode* head,int k){
    if(!head){
        return nullptr;
    }
    ListNode* p = head;
    bool flag = true;
    for(int i = 1;i<=k;i++){
        if(p){
            p = p->next;
        }else{
            flag = false;
            break;
        }
    }
    if(!flag){
        return head;
    }
    ListNode* prev = nullptr;
    ListNode* curr = head;
    for(int i = 1;i<=k;i++){
        auto next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    ListNode* last = reverseKGroup(p,k);
    head->next = last;
    return prev;
}