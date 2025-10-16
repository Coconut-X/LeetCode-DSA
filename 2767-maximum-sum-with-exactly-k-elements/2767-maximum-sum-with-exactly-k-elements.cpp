class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int m = *max_element(nums.begin(), nums.end());
        int score = 0;
        while(k){
            score+=m;
            k--;
            m++;
        }
        return score;
    }
};