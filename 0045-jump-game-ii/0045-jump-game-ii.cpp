class Solution {
public:


    vector<int> mep;
    int minJump(vector<int>&nums, int s, int i){
        if(i>=s-1){
            return 0;
        }

        if(nums[i]==0) return 10001;

        if (mep[i]!=10001) return mep[i];

        for(int k = 1; k<=nums[i];k++)
        {
            mep[i] = min(mep[i],1 + minJump(nums, s, i + k));
        }

        return mep[i];
    }


    int jump(vector<int>& nums) {

        mep.resize(nums.size(),10001);
        return minJump(nums, nums.size(), 0);
        
    }
};