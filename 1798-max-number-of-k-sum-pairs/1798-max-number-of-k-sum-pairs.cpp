class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int count=0;
        while(true)
        {
            int l=0, r=nums.size()-1;

            bool found=false;
            while(l<r)
            {
                if (nums[l] == 0) {
                    l++; 
                    continue;
                }
                if (nums[r] == 0) {
                    r--;
                    continue;
                }

                if(nums[l]+nums[r]==k)
                {
                    found=true;
                    nums[l]=0;
                    nums[r]=0;
                    count++;
                }
                if(nums[l]+nums[r]>k) r--;
                else if(nums[l] + nums[r] < k) l++;

            }

            if(!found)
                break;

        }
            return count;
    }
};