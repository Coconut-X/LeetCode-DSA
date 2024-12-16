class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        for(int i=1;i<=k;i++)
        {
        //     nums[distance(nums.begin(),min_element(nums.begin(),nums.end()))]=*min_element(nums.begin(),nums.end())*multiplier;
        // }

        auto it=min_element(nums.begin(),nums.end());
        *it=*it*multiplier;
        }

        return nums;
    }
};