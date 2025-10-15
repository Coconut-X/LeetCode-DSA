class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int total = accumulate(nums.begin(), nums.end(),0);
        int s = 0;
        vector<int>ans;
        for(int i = nums.size() - 1; i >=0; i--){
            s+=nums[i];
            ans.push_back(nums[i]);
            if(2*s> total) break; //s > total - s becomes 2s > total
        }
        return ans;
    }
};