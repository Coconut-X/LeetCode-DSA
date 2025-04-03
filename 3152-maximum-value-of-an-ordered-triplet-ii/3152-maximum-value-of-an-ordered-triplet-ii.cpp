class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {

        int n = nums.size();
        vector<int>MaxS(nums.size(),0);
        vector<int>MaxE(nums.size(),0);
        MaxS[0]=nums[0];
        MaxE[n-1] = nums[n-1];
        for(int i=1;i<nums.size();i++)
        {
            MaxS[i] = max(nums[i],MaxS[i-1]);
        }

        for(int i=n-2; i>=0;i--){
            MaxE[i]=max(nums[i],MaxE[i+1]);
        }

        long long m =0;

        for(int j = 1;j<n-1;j++)
        {
            m = max((long long) m, (long long)(MaxS[j-1] - nums[j])*MaxE[j+1]);
        }

        return m;



        
    }
};