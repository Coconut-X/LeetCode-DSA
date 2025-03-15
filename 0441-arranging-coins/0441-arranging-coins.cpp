class Solution {
public:
    int arrangeCoins(int n) {
        //(1-2)   => 1              2
        //(3-5)   => 2              3
        //(6-9)   => 3              4
        //(10-14) => 4              5

        return (-1 + sqrt(1+(long)8*n))/2;

        long x = 2;
        for(long cur=1;cur<=n;){
            cur+=x++;
        }

        return x - 2; // -1 to turn to index, another -1 bcz loop runs one time extra

        
    }
};