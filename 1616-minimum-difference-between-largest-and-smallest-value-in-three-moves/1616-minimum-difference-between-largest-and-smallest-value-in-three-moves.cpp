class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 3) return 0;
        // partial_sort(begin, begin+4, end) rearranges the array so that:
        // the first 4 elements are the smallest 4 numbers, sorted ascending,
        // the rest are unsorted (we don’t care about them).
        partial_sort(nums.begin(), nums.begin() + 4, nums.end());

        // This does the same thing — but in reverse:
        // rbegin() iterates from the end,
        // greater<int>() ensures we get descending order for the largest 4.
        partial_sort(nums.rbegin(), nums.rbegin() + 4, nums.rend(), greater<int>());

        int m = INT_MAX;
        for(int i = 0; i <= 3; i++){
            m = min(m, nums[nums.size()-1-3+i] - nums[i]);
        }
        return m;
    }
};