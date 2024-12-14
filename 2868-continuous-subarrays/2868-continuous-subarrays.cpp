class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        map<int,int> mp;

        int left,right=0;
        int n=nums.size();

        long long sum=0;
        while(right<n){
            
          mp[nums[right]]++;
          while(mp.rbegin()->first-mp.begin()->first>2){
            mp[nums[left]]--;
            if(mp[nums[left]]==0){
                mp.erase(nums[left]);
            }
            left++;
          }
          // k-n+1 gives all continous subarrays in that range 
          //the above loop removes all the unnecessary ones
          sum+=right-left+1;
          right++;
        }
        return sum;       
    }
};