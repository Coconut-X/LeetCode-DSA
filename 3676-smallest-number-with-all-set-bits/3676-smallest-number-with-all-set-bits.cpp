class Solution {
public:
    int smallestNumber(int n) {
        if(n==1) return 1;
        int c = (log2(n)+1);
        return pow(2,(int)c)-1;
    }
};