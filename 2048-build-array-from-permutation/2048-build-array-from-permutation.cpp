class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> n;
        for(int i=0;i<nums.size();i++){
            n.push_back(nums[nums[i]]);
        }
        return n;
    }
};