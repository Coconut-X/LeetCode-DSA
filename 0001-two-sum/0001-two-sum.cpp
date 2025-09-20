class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,bool> mep;
        unordered_map<int,int>index;
       // mep[-2,2,6] = true;
        //index[]
        for(int i = 1; i < nums.size(); i++){
            mep[nums[i]-target] = true;
            index[nums[i]-target] = i;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(mep[-nums[i]]){

                if(i == index[-nums[i]]){
                    continue;
                }
                return {i, index[-nums[i]]};
            }
        }

        return {};
        
    }
};