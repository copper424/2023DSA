#include"ListNode.h"
#include<stack>
// struct ListNode {
//     int val;
//     ListNode *next = nullptr;
//     ListNode(int x) : val(x){}
// };

bool isPalindrome(ListNode* head){
    if(!head || !head->next){
        return true;
    }
    int sz = 0;
    for(ListNode* p = head;p != nullptr;p = p->next){
        sz += 1;
    }
    std::stack<int> myStack;
    ListNode* p = head;
    for(int i = 0;i < sz / 2;i++,p = p->next){
        myStack.push(p->val);
    }
    // isOdd
    if((sz & 0x1) == 1){
        p = p->next;
    }
    for(;p != nullptr;p = p->next){
        int val = myStack.top();
        myStack.pop();
        if(val != p->val){
            return false;
        }
    }
    return true;
}