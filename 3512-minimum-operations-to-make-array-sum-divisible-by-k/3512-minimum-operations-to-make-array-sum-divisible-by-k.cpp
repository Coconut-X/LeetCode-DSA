class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int>mods (nums.size(),0);
        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            sum+=nums[i];
            mods[i] = nums[i]%k;
        }

        sort(mods.begin(), mods.end(), greater<int>());


        int count = 0;
        int i = 0;
        while(sum%k){
            if(mods[i] = sum%k){
                count+=mods[i];
                sum -= mods[i];
            }
        }
        return count;
    }
};