class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        int i = 0;
        while(i < nums.size() and nums[i] < 0 and k > 0){
                nums[i] = -nums[i];
                k --;
                i++;
        }

        if(k%2==1 ){
            //if odd, flip one time the minimum element
            int idx = min_element(nums.begin(), nums.end()) - nums.begin();
            nums[idx] = -nums[idx];
        }
        //if it was even it means we can flip the min element even times and it will stay the same so we can ignore this flip

        return accumulate(nums.begin(), nums.end(),0);
    }
};