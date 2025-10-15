class Solution {
public:
    string largestOddNumber(string nums) {
        int index = 0;
        bool found = false;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] % 2 == 1){
                index = i;
                found = true;
                break;
            }
        }
        if(!found) return "";
        return nums.substr(0, index + 1);
    }
};