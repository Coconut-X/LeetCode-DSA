class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int m;
        int index = -1;

        for(int i = nums.size()-2; i>=0;i--){
            if(nums[i] < nums[i+1]){
                index = i;
                m = nums[i];
                break;
            }
        }

        if(index == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i = nums.size()-1;i>=0;i--){
            if(nums[i] > m){
                swap(nums[i], nums[index]);
                sort(nums.begin()+index+1,nums.end());
                return;
            }
        }

        
    }
};