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
    ListNode* rotateRight(ListNode* head, int k) {
    
    if(head==nullptr || head->next==nullptr) return head;
    
    int s=1;
    ListNode*temp=head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
        s++;
    }
    k=k%s;

    ListNode* prev=nullptr;
    ListNode* current=head;
        for(int i=1;i<=k;i++)
        {
            while(current->next!=nullptr)
            {
                prev=current;
                current=current->next;
            }
            prev->next=nullptr;
            current->next=head;
            head=current; 

        }

    return head;

        
    }
};