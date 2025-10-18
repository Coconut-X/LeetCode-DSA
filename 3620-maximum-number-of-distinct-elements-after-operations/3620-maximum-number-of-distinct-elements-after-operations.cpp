class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int index = 1;
        for(int i = 0; i < nums.size(); i++)  nums[i] = i==0 ?nums[i] - k: (max(nums[i-1]+1, nums[i] - k) > nums[i] + k )? nums[i] + k : max(nums[i - 1]+1, nums[i] - k) + ++index - index;
        return index;
    }
};