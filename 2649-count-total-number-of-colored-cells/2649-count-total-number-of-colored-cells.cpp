class Solution {
public:
    long long coloredCells(int n) {

        //n = 1        1
        //n = 2        5  , 4(2-1) +1 
        //n = 3        13 , 4(5) - 6 -1    4(2) +5=13
        //n = 4        25 ,  4(13)      4(3) +13
        //n = 5        1

        if(n==1) return 1;
        long long curr = 1;


        for(int i=2;i<=n;i++)
        {
            curr=4*(i-1) + curr;
        }

        return curr;
    }
};