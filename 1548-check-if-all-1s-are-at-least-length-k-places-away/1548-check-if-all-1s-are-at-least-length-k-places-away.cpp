class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int i = 0; 
        while(i < nums.size() and nums[i] == 0) i++;
        int dist = i;
        i++;
        while(i < nums.size()){
            if(nums[i]==1){
                if( i-dist <= k) return false;
                dist = i;
            }
            i++;
        }

        return true;
    }
};