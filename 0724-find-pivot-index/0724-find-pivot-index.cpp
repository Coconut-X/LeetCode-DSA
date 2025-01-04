class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        unordered_map<int,int> sums;

        for(int i=0;i<nums.size();i++)
            sums[i]+=(i==0?nums[i]: nums[i]+sums[i-1]);
        
        for(int i=0;i<nums.size();i++)
            if(sums[i-1]==sums[nums.size()-1]- sums[i])

                return i;
        return -1;
        
    }
};