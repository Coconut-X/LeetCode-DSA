class Solution {
public:

    int binarySearch(vector<int>&nums, int low, int high, int sum){
        
        // while(low<high){
        //     int mid = low + (high-low)/2;
        //     if(nums[mid] < sum and nums[mid+1]>=sum){
        //         return mid;
        //     }
        //     if(nums[mid] < sum){
        //         low = mid+1;
        //     }
        //     else{
        //         high = mid - 1;
        //     }
        // }


        return -1;
    }


    int triangleNumber(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int count = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i+1; j < nums.size(); j++){
                auto it = lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]);
                int k = distance(nums.begin(), it); 
                count += k - (j + 1); 
            }
        }
        return count;
    }
};