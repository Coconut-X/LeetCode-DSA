class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> mep;
        for(int i = 0; i < nums.size(); i++){
            mep[nums[i]]++;
            if(mep[nums[i]] == nums.size()/2) return nums[i];
        }
        return 0;
    }
};