class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int,bool>mep;
        for(auto &n:nums) mep[n] = true;

        while(mep[original]){
            mep[original] = false;
            original*=2;
        }
        return original;
    }
};