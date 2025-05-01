class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>prefix, freq;

        prefix[0] = nums[0];

        for(int i=1;i<nums.size();i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(prefix[i]==k) count++;
            count+=freq[prefix[i]-k];
            freq[prefix[i]]++;
        }

        return count;
        
    }
};