class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int maxEnding = 0;
        int res =INT_MIN;

        for(int i=0;i<nums.size();i++){
            maxEnding = max (nums[i], nums[i]+maxEnding);
            res = max (res,maxEnding);
        }
        return res;
        
    }
};