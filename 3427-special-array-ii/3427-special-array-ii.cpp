class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n, 0);

        for (int i = 0; i < n - 1; i++) 
        {
            prefix[i + 1] = prefix[i] + ((nums[i] ^ nums[i + 1]) & 1);
        }

        vector<bool> ans;
        for (auto  query : queries) 
        {
            int s = query[0], e = query[1];
            int validPairs = prefix[e] - prefix[s];
            ans.emplace_back(validPairs == (e - s)); 
        }

        return ans;
    }
};
