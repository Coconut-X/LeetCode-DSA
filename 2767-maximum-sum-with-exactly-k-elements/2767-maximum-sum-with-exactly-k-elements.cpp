class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int m = *max_element(nums.begin(), nums.end());
        // 1  2  3  4   5    6   7 
        // 1  3  6  10  15  21   28
        // 28-10
        //int left = (m)*(m-1)/2,     right = (m+k)*(m+k-1)/2;
        //return ((m+k)*(m+k-1) - (m)*(m-1))/2;
        //mm+mk -m  mk +kk -k   -mm +m
        //mk +  mk +kk -k  
        //2mk +kk -k => k(2m+k-1) => k(2m+k-1)/2 => k*(m << 1 + k - 1) >> 1
        //or divide by two each term we get mk +kk/2 -k/2 => mk + k(k-1)/2  => m*k + (k*(k-1) >> 1)
        //this one is better so imma use this
        return m*k + (k*(k-1) >> 1);
        //return k*((m << 1) + k - 1) >> 1;
    }
};