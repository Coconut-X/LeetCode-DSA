class Solution {
public:
    int arrangeCoins(int n) {
        //(1-2)   => 1              2
        //(3-5)   => 2              3
        //(6-9)   => 3              4
        //(10-14) => 4              5

        int ans=0;
        long x = 2;
        for(long cur=1;cur<=n;){

            
            ans=x;
            cur+=x;

            x++;
        }

        return ans - 1;

        
    }
};