class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        for(int i=0;i<nums.size();i++)
        {
            bool found=false;
            for(int j=0;j<nums.size()-1;j++)
            {
                if(!nums[j] and nums[j+1])
                {
                    swap(nums[j],nums[j+1]);
                    found=true;
                }
            }

            if(!found) return;
        }
        
    }
};