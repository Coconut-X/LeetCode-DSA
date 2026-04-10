class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int count = INT_MAX;
        for(int i = 0 ; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                for(int k = j+1; k < nums.size(); k++){
                    if(nums[i] == nums[j] and nums[j] == nums[k]){
                        count = min(count, abs(i - j) + abs(j - k) + abs(k - i));
                        // cout <<count << " " << i << " " << j << " " << k << endl;
                    }
                }
            }
        }
        return count == INT_MAX ? -1 : count;
    }
};