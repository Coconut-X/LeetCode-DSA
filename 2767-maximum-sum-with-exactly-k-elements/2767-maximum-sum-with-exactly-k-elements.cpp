class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int m = *max_element(nums.begin(), nums.end());
        // 1  2  3  4   5    6   7 
        // 1  3  6  10  15  21   28
        // 28-10
        int left = (m)*(m-1)/2;
        int right = (m+k)*(m+k-1)/2;
        //cout<<left<<" "<<right;
        return right - left;
    }
};