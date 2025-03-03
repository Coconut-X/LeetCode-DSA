class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        stack<int> greater;
        stack<int> smaller;
        int pc=0;

        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]>pivot) greater.push(nums[i]);
            else if(nums[i]<pivot) smaller.push(nums[i]);
            else pc++;
        }

        vector<int> ans;

        while(!smaller.empty())
        {
            ans.push_back(smaller.top());
            smaller.pop();
        }

        while(pc)
        {
            ans.push_back(pivot);
            pc--;
        }

        while(!greater.empty())
        {
            ans.push_back(greater.top());
            greater.pop();
        }

        return ans;

       
    }
};