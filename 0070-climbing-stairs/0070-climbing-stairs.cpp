class Solution {
public:
    unordered_map<int,int>mep;
    int climb(int c, int&n){
        if(c>=n){
            return c==n;
        }
        if(mep[c]) return mep[c];
        return mep[c] = climb(c+1,n)+climb(c+2,n);
    }
    int climbStairs(int n) {
        return climb(1,n)+climb(2,n);
    }
};