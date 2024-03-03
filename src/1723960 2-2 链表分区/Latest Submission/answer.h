#include"ListNode.h"
ListNode* partList(ListNode* list, int x){
    auto p1 = new ListNode;
    auto p2 = new ListNode;
    auto p3 = p1;
    auto p4 = p2;
    for(auto p = list;p != nullptr;p = p->next){
        if (p->val < x){
            p1->next = p;
            p1 = p1->next;
        }else{
            p2->next = p;
            p2 = p2->next;
        }
    }
    p1->next = p4->next;
    p2->next = nullptr;
    auto ans = p3->next;
    delete p3;
    delete p4;
    return ans;
}