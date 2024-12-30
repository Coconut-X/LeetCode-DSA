class Solution {
public:

    

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1,0);
        dp[0]=1;
        const int mod=1000000007;
        for(int i=1;i<=high;i++)
        {
            if(i-zero>=0)
            {
                dp[i]+=dp[i-zero];
                dp[i]%=mod;
            }

            if(i-one>=0)
            {
                dp[i]+=dp[i-one];
                dp[i]%=mod;
            }
        }

        int result=0;
        for(int i=low;i<=high;i++)
        {
            result+=dp[i];
            result%=mod;
        }

        return result;
        
    }
};