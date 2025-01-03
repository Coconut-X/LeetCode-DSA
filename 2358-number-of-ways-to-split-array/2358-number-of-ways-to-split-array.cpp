class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        unordered_map<long long,long long> left;
        long long l=0;
        for(int i=0;i<nums.size();i++)
            left[i]+=( i==0? nums[i]: left[i-1]+nums[i]);

        int count=0;
        for(int i=0;i<nums.size()-1;i++)
            if(left[i]>= left[nums.size()-1] - left[i])
                count++;

        return count;
    }
};