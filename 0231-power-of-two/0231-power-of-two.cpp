class Solution {
public:
    bool isPowerOfTwo(long n) {

        //return n&&!(n&(n-1));
        if(n<=0) return false;
        long int count = __builtin_popcount(n);
        return (count==1 or count==0);
        
    }
};