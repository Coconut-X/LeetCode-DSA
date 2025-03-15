class Solution {
public:

    int rob(vector<int>&nums, int mid){
        int robbed=0;
        for(int i=0;i<nums.size();i++){
            if(mid>=nums[i]) robbed++, i++; //skip next;
        }
        return robbed;
    }

    int minCapability(vector<int>& nums, int k) {

        int n = nums.size();
        

        int l=*min_element(nums.begin(), nums.end());
        int r=*max_element(nums.begin(), nums.end());
        int ans=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;  
            int guess=rob(nums,mid);
            if(guess>=k){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return l;
    }
};