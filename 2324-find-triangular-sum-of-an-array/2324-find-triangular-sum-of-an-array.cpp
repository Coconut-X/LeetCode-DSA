class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int index = nums.size()-1;
        vector<int> temp = nums;
        while(index!=0){
            for(int i = 0; i <= index-1; i++){
                //int a = nums[i], b = nums[i+1];
                nums[i] = (temp[i]+temp[i+1])%10;
            }
            temp = nums;
            index--;
        }
        return nums[0];
    }
};