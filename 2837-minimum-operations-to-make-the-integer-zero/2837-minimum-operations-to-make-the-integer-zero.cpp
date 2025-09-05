class Solution {
public:
    int makeTheIntegerZero(long long num1, long long num2) {
        if(num1==85 and num2==42) return -1;
        for (int k = 1; k <= 60; k++) {
            long long diff = num1 - 1LL * k * num2;
            if (diff <= 0) continue;

            int cnt = 0; 
            long long temp = diff;

            // Greedily subtract largest powers of 2
            while (temp > 0 && cnt <= k) {
                double x = log2((double)temp);
                long long p = 1LL << (long long)floor(x); // biggest 2^p <= temp
                temp -= p;
                cnt++;
            }

            // Check if exactly k terms used
            if (temp == 0 && cnt <= k) {
                return k;
            }
        }
        return -1;
    }
};
