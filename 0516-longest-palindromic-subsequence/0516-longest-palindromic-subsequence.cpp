

class Solution {
public:

    int lps(string&s, int low,int high,vector<vector<int>>&dp)
    {
        if(low>high) return 0;
        if(dp[low][high]) return dp[low][high];
        if(low==high) return 1; //one char same at same index
        if(s[low]==s[high]) 
        {
            return dp[low][high] = 2 + lps(s,low+1,high-1,dp);
        }
        

        int incLow = lps(s,low+1,high,dp);
        int decHigh = lps(s,low,high-1,dp);
        return dp[low][high] = max(incLow,decHigh);

    }

    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(1000,vector<int>(1000,0));
        return lps(s,0,s.size()-1,dp);
       
    }
};