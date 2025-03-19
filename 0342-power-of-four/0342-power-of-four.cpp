class Solution {
public:
    bool isPowerOfFour(long n) {
        if(n<=0) return false;
        return log2(n) / log2(4) - floor(log2(n) / log2(4)) == 0;
        
        
    }
};