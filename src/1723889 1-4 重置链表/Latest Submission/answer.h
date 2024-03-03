#include"ListNode.h"
ListNode* resetList(ListNode* head){
    if (head == nullptr){
        return head;
    }
    ListNode odd;
    ListNode even;
    allNodes -= 2;
    ListNode* p1 = &odd;
    ListNode* p2 = &even;
    for(int i = 1; head != nullptr;i++){
        if (i % 2 == 1){
            p1->next = head;
            head = head->next;
            p1 = p1->next;
            p1->next = nullptr;
        }else{
            p2->next = head;
            head = head->next;
            p2 = p2->next;
            p2->next = nullptr;
        }
    }
    p1->next = even.next;
    return odd.next;
}