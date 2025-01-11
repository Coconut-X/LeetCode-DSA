class Solution {
public:

    unordered_map<long,long> dp;

    int numTilings(int n) {
        const int MOD=1e9+7;
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        int a=1, b=2, c=5, ans;

        if(n==1) return 1; if(n==2) return 2;if(n==3) return 5;

        for(int i=4;i<=n;i++)
            //dp[i]=(2*dp[i-1]+dp[i-3])%MOD;
        {
            ans=((2*c)%MOD+a)%MOD, a=b, b=c, c=ans;
        }

        return ans;
        
    }
};