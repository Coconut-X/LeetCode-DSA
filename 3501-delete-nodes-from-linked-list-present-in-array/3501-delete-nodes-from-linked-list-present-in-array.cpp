class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> toDelete(nums.begin(), nums.end());
        ListNode dummy(0);      
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr) {
            if (toDelete.count(curr->val)) {
                prev->next = curr->next; 
            } else {
                prev = curr;
            }
            curr = curr->next;
        }

        return dummy.next;
    }
};
