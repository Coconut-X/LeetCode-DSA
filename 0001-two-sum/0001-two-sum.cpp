class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        for(int i=0,j=0;i<nums.size();j++)
        {
            if(i!=j and nums[i]+nums[j]==target) return {i,j};
            if(j==nums.size()-1) i++,j=0;
        }
        
        return {0,0};
    }
};