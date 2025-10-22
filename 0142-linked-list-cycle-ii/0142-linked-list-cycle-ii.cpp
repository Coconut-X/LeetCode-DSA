/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

   
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp = head;
        unordered_map<ListNode*, bool> mep;
        while(temp){
            if(mep[temp]) return temp;
            mep[temp] = true;
            temp = temp->next;
        }

        return nullptr;
    }
};