class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<bool>vals(value,false);
        unordered_map<int,int>freq;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0){
                //-X = -X + ceil(X/V);
                //-10 = -10 + 7*ceil(10/7) = -10+7*ceil(1.something) = -10+7*2 = 4 
                nums[i] = nums[i] + value*(int)ceil((double)-nums[i]/value); //first positive number after adding value k times
            }
            //always less than value due to mod
            //cout<<nums[i]%value<<" ";
            freq[nums[i]%value]++;
        }

        int count = 0;
        //find continuous mods available
        // find count of continuous whole numbers 
        while(true){
            if(freq[count%value] == 0) break; //mex not available
            freq[count%value]--;
            count++;
        }
        return count;
    }
};