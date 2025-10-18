class Solution {
public:

    int minKadane(vector<int>&nums){
        int n = nums.size();
        int cur = nums[0], res = nums[0];
        for(int i = 1; i < n; i++){
            cur = min(nums[i], nums[i]+cur);
            res = min(res,cur);
        }
        return res;
    }

    int maxKadane(vector<int>&nums){
        int n = nums.size();
        int cur = nums[0], res = nums[0];
        for(int i = 1; i < n; i++){
            cur = max(nums[i], nums[i]+cur);
            res = max(res,cur);
        }
        return res;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        
        int maxSumSubarray = maxKadane(nums);
        if (maxSumSubarray < 0)
            return maxSumSubarray;
        int minSumSubarray = minKadane(nums);
        
        int total = accumulate(nums.begin(), nums.end(),0);
        return max(maxSumSubarray,total - minSumSubarray);
    }
};