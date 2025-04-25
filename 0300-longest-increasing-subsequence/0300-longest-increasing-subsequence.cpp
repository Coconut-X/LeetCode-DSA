class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> bucket;
        bucket.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>bucket.back())
                bucket.push_back(nums[i]);
            if(nums[i]<bucket.back())
            {
                auto it = lower_bound(bucket.begin(),bucket.end(),nums[i]);
                *it = nums[i];
            }

        }

        return bucket.size();
        
    }
};