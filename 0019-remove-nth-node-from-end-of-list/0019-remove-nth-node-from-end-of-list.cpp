/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    
    ListNode* slow = head;
    ListNode* fast = new ListNode(0);
    fast = head;
    int i=1;
    while(i<=n){
        fast = fast->next;
        i++;
    }
    ListNode* prev= slow;
    while(fast!=nullptr){
        prev = slow;
        fast = fast->next;
        slow =slow->next;
    }

    if(head==slow){
        return head->next;
    }
    prev->next= slow->next;
    return head;
        
    }
};