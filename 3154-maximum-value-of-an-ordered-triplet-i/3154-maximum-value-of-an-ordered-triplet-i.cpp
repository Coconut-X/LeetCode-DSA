#define LL long long
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {

        LL m= LLONG_MIN;
        for(int i=0;i<nums.size()-2;i++)
        {
            for(int j=i+1;j<nums.size()-1;j++)
            {
                for(int k=j+1;k<nums.size();k++)
                {
                    if(nums[j]>nums[i]) continue;
                    m = max(m,(LL)(nums[i]-nums[j])*nums[k]);
                }
            }
        }

        return (m>0?m:0);
        
    }
};