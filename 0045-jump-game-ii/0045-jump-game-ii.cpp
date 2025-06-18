class Solution {
public:
    vector<int> m;
    Solution(){
        m.resize(10001,INT_MAX);
    }

    int minJump(vector<int>&nums, int index){
        if(index>=nums.size()){
            return INT_MAX;
        }
        if(index >= nums.size()-1){
            return 0;
        }

        if(m[index]!=INT_MAX){
            return m[index];
        }

        for(int i=1;i<=m[index];i++){
            m[index] = min(m[index],1+minJump(nums,index+i));
        }
        return m[index];
    }

    int jump(vector<int>& nums) {
        return minJump(nums,0);
    }
};