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

    int gcd(int a, int b)
    {
        int g;
    int i=1;
        while(i<=a && i<=b)
        {
            if(a%i==0 && b%i==0)
            {
                g=i;
            }
            i++;
        }

       return g;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {


        ListNode*temp=head;
        while(temp != nullptr && temp->next != nullptr)
        {
          
           ListNode* newNode = new ListNode(gcd(temp->val,temp->next->val));
           ListNode* Next=temp->next;
           temp->next=newNode;
           newNode->next=Next;

            temp=temp->next->next;
        }
        
        return head;
    }
};