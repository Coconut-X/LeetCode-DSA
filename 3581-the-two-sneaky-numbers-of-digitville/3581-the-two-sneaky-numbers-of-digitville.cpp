class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>sneaky;
        bitset<100>mep;
        
        int s = nums.size();
        for(int i = 0; i < s; i++){
            if(mep.test(nums[i])) sneaky.push_back(nums[i]);
            mep.set(nums[i]);  
        }
        return sneaky;
    }
};