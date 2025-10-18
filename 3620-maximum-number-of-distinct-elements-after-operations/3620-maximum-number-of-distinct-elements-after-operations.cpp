class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_set<int>unique;
        nums[0] = nums[0] - k; ////min range possible
        unique.insert(nums[0]);        
        for(int i = 1; i < nums.size(); i++){
            nums[i] = (max(nums[i-1]+1, nums[i] - k) > nums[i] + k )? nums[i] + k: max(nums[i - 1]+1, nums[i] - k);
            unique.insert(nums[i]);        
        }
        return unique.size();
    }
};