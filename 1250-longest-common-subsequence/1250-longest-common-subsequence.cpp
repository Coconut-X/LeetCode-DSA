class Solution {
public:

    vector<vector<int>>dp;
    int brute(string& t1, string& t2, int n, int m)
    {
        if(n==0 or m==0) return 0;
        if(dp[n-1][m-1]!=-1)
            return dp[n-1][m-1];
        if(t1[n-1] == t2[m-1])
            return dp[n-1][m-1] = 1 + brute(t1,t2,n-1,m-1);
        else 
            return dp[n-1][m-1] = max(brute(t1,t2,n-1,m),brute(t1,t2,n,m-1));  

    }

    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.size(),vector<int>(text2.size(),-1));
        return brute(text1,text2,text1.size(),text2.size());   
    }
};