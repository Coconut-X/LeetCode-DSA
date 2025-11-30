class Solution {
public:
    long long minSubarray(vector<int>& nums, int p) {
        
        int n = nums.size();
        
        long long total = accumulate(nums.begin(), nums.end(), (long long)0);
        
        int need = total % p;

        if (need == 0) return 0;

        unordered_map<int, int> mpp;
        mpp[0] = -1;

        long long pref = 0;  
        int ans = n;

        for (int i = 0; i < n; i++) 
        {
            pref = (pref + nums[i]) % p;
            int target = (pref - need + p) % p;
            if (mpp.find(target) != mpp.end()) 
                ans = min(ans, i - mpp[target]);

            mpp[pref] = i;
        }

        if (ans == n) return -1;

        return ans;
    }
};
