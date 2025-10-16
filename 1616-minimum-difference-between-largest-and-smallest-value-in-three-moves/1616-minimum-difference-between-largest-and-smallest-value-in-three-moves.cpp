class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 3) return 0;
        sort(nums.begin(), nums.end());
        int m = INT_MAX;
        for(int i = 0; i <= 3; i++){
            m = min(m, nums[nums.size()-1-3+i] - nums[i]);
        }
        return m;
    }
};