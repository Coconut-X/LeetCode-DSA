class Solution {
public:
    vector<int> m;
    Solution(){
        m.resize(10001,10001);
    }

    int minJump(vector<int>&nums, int index){
       
        if(index >= nums.size()-1){
            return 0;
        }

        if(nums[index]==0){
            return 10001;
        }

        if(m[index]!=10001){
            return m[index];
        }

        for(int i=1;i<=nums[index];i++){
            m[index] = min(m[index],1+minJump(nums,index+i));
        }
        return m[index];
    }

    int jump(vector<int>& nums) {
        return minJump(nums,0);
    }
};