class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int s = log2(n) + 1;
        int mask = pow(2,s) - 1;
        return n ^ mask;
    }
};