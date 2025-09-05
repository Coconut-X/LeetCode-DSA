class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        //n1 = k*n2+pow(2,i);
        //n1 - k*n2 = 2^i
        //log2(n1-k*n2)= i;
        // for(int k = 1; k<=60;k++){
        //     float x = log2(num1-k*num2);
        //     //if x is integer return k

        // }
        // return -1;
        for (long long k = 1; k <= 60; k++) {
            long long diff = num1 - k * num2;
            if (diff < 0) continue;
            int bits = __builtin_popcountll(diff);
            if (bits <= k && k <= diff) {
                return k;
            }
        }
        return -1;
    }
};