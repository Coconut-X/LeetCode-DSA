class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mx (n,INT_MIN);
        vector<int> mn (n,INT_MAX);
        mx[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            mx[i] = max(mx[i - 1], nums[i]);
        }
        reverse(nums.begin(), nums.end());
        mn[0] = nums[0]; 
        for(int i = 1; i < n ; i++){
            mn[i] = min(mn[i - 1], nums[i]);
        }

        reverse(mn.begin(), mn.end());
        int idx = -1;
        for(int i = 0; i < n ; i++){
            int instscore = mx[i] - mn[i];
            if(instscore <= k){
                idx = i;
                break;
            }
        }
        return idx;
    }
};