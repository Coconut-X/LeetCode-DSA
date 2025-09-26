class Solution {
public:

    int triangleNumber(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int count = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i+1; j < nums.size(); j++){
                auto it = lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]);
                int k = distance(nums.begin(), it); 
                count += k - (j + 1); 
            }
        }
        return count;
    }
};