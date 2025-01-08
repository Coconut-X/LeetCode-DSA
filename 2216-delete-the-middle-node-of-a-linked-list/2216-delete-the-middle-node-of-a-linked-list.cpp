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
    ListNode* deleteMiddle(ListNode* head) {
        
        if(!head or !head->next) return nullptr;

        ListNode* temp=head;
        int count=0;
        while(temp)
        {
            temp=temp->next;
            count++;
        }

        count/=2;

        int x=0;
        temp=head;
        ListNode* prev=head;
        while(x < count)
        {
            prev=temp;
            temp=temp->next;
            x++;
        }

        prev->next=temp->next;
        delete temp;

        return head;


    }
};