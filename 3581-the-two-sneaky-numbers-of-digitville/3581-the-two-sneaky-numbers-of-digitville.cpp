class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>sneaky;
        __int128_t set = 0LL;
        int s = nums.size();
        for(int i = 0; i < s; i++){
            __int128_t mask = (__int128_t)1 << nums[i];
            if(set & mask) sneaky.push_back(nums[i]);
            set |= mask;
        }
        return sneaky;
    }
};