class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        
        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }

        int index = 0;
        bool stopatsame = false;
        bool stopat0 = false;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i-1]) {
                index = i;
            }
            else if (nums[i] == nums[i-1]) { // 1, 2, 3, 3, 2, 1-> [1,2,3], [3,2,1] when peak repeats
                stopatsame = true;
                break;
            }
            else {
                break; // found peak
            }
        }

        if (index == 0) stopat0 = true;

        int x = 0;
        if (stopatsame) x = 1;

        // check strictly decreasing part
        for (int i = index + 1 + x; i < n; i++) {
            if (nums[i] >= nums[i-1]) {
                return -1;
            }
        }

        if (stopat0) {
            return abs(nums[0] - (prefix[n-1] - nums[0]));
        }

        if (stopatsame) {
            return abs((prefix[index] << 1) - prefix[n-1]);
        }

        if (index == n-1) {
            return abs(nums[index] - prefix[index-1]);
        }

        long long minabs = LLONG_MAX;

        // include index in right
        if (index-1 >= 0) {
            long long l = prefix[index-1];
            long long r = prefix[n-1] - l;
            minabs = min(minabs, abs(l-r));
        }

        // include index in left
        long long l = prefix[index];
        long long r = prefix[n-1] - l;
        minabs = min(minabs, abs(l-r));

        return minabs;
    }
};
