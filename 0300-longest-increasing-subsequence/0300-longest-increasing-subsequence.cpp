#define all(v) v.begin(),v.end()
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> v;
        v.push_back(nums[0]);

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>v.back())
            {
                v.push_back(nums[i]);
            }
            else if(nums[i]<v.back())
            {
                auto it = lower_bound(all(v),nums[i]);
                *it=nums[i];
            }
        }

        return v.size();
    }
};