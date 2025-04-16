class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumMap;
        prefixSumMap[0] = -1;

        int currentSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            currentSum = (currentSum + nums[i]) % k;

            if (prefixSumMap.count(currentSum)) {
                if (i - prefixSumMap[currentSum] > 1) {
                    return true;
                }
            } else {
                prefixSumMap[currentSum] = i;
            }
        }
        return false;
    }
};