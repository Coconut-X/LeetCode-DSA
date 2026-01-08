class Solution {
public:

    int brute(vector<int>&n1, vector<int>&n2, int i, int j, vector<vector<int>>&dp){
        if(i >= n1.size() or j >= n2.size()) return INT_MIN;
        if(dp[i][j]!=INT_MIN) return dp[i][j];
        dp[i][j] = max({n1[i]*n2[j] + max(0, brute(n1,n2,i+1,j+1,dp)), brute(n1,n2,i+1,j,dp), brute(n1,n2,i,j+1,dp)});
        return dp[i][j];
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size(), vector<int>(nums2.size(), INT_MIN));
        return brute(nums1,nums2,0,0,dp);
    }
};