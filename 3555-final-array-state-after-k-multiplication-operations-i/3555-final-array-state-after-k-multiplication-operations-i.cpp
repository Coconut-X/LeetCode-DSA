class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        for(int i=1;i<=k;i++)
        {
            auto it=min_element(nums.begin(),nums.end());
            *it=*it*multiplier;
        }

        return nums;
    }
};