class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        for(int i=0,j=i+1;i<nums.size()-1 and j<nums.size();j++)
        {
            if(i!=j and nums[i]+nums[j]==target) return {i,j};
            if(j==nums.size()-1) i++,j=0;
        }
        return {0,0};
    }
};