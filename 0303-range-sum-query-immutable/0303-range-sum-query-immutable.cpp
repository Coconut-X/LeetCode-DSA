class NumArray {
public:
    vector<int> pre;
    NumArray(vector<int>& nums) {

        pre.resize(nums.size(),0);
        pre[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            pre[i] = pre[i-1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return pre[right] - (left==0?0:pre[left-1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */