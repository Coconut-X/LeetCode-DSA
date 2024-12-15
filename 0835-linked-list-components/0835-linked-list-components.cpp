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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int,int> myset;
        for(auto i: nums)
        myset[i]++;;

        ListNode* temp=head;
        int count=0;
        bool started=false;;
        while(temp)
        {
           if(myset[temp->val]==1 and !started)
           {
            count++;
            started=true;
           }
           else if(myset[temp->val]==0 and started) started=false;
            temp=temp->next;

        }
        return count;
    }
};