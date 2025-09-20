class Solution {
public:
    unordered_map<int, pair<int,int>> mep;
    vector<int> twoSum(vector<int>& nums, int target) {

        for(int i = 1; i < nums.size(); i++){
            mep[nums[i]-target] = {true,i};
        }

        for(int i = 0; i < nums.size(); i++){
            auto p = mep[-nums[i]];
            if(p.first){
                if(i == p.second){
                    continue;
                }
                return {i, p.second};
            }
        }
        return {};
    }
};