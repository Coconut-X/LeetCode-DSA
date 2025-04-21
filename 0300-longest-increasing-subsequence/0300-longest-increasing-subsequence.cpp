class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        vector<int> len(nums.size(), 1); 
        int m=1;

        for (int i = nums.size() - 2; i >= 0; i--) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] < nums[j]) {
                    len[i] = max(len[i], len[j] + 1);
                }
            }
            m = max(m, len[i]);  
        }

        return m; 
    }
};
