class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> arr;
        while(head!=nullptr)
        {
            arr.push_back(head->val);
            head= head->next;
        }
        int j= arr.size()-1;
        int sum=0;
        for(int i=0;i<=arr.size()/2;i++)
        {
            if(arr[i]+arr[j]>sum)
                sum = arr[i] + arr[j];
            j--;
        }

        return sum;
        
    }
};