class Solution {
public:

    unordered_map<long,long> dp;

    int numTilings(int n) {
        const int MOD=1e9+7;
        int a=1, b=2, c=5, ans;
        if(n<=3) return n<=2? n: 5;

        for(int i=4;i<=n;i++)
            ans=((2*c)%MOD+a)%MOD, a=b, b=c, c=ans;

        return ans;
    }
};