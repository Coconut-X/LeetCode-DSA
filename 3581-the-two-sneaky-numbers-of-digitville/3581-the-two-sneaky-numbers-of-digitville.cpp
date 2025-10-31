class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>sneaky;
        unordered_map<int,bool>mep;
        int s = nums.size();
        for(int i = 0; i < s; i++)
        {
            if(mep[nums[i]])sneaky.push_back(nums[i]);
            mep[nums[i]]= true;
            
        }
        return sneaky;
    }
};