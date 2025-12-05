class Solution {
public:
    int countPartitions(vector<int>& nums) {
        return !(accumulate(nums.begin(), nums.end(), 0) & 1 ) * (nums.size()-1);
    }
};