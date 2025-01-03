class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        unordered_map<long long,long long> left;
        long long l=0;
        for(int i=0;i<nums.size();i++)
        {
            l+=nums[i];
            left[i]=l;
        }

        int count=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(left[i]>= left[nums.size()-1] - left[i] )
            {
                count++;
            }
        }


        return count;
        
    }
};