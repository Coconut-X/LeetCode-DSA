class Solution {
public:
    int climbStairs(int n) {
        if(n<=3) return n;
        int s1 = 1;
        int s2 = 2;
        int total = 0;
        for(int i = 3; i <=n; i++){
           total = s1+s2;
           s1=s2;
           s2=total;
        }
        return total;
    }
};